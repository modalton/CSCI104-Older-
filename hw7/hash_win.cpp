#include "hash_win.h"


HashWin::HashWin(std::map<std::string, std::vector<Tweet*> >* x){
	htags = x;
	refresh_btn = new QPushButton("Refresh");
	refresh_btn->setFixedWidth(80);
	connect(refresh_btn, SIGNAL(clicked()), this, SLOT(refresh()));
	test = new QPushButton("hello");
	connect(test, SIGNAL(clicked()), this, SLOT(refresh()));

	tweet_text = new QListWidget;

	hash_option = new QComboBox;
	hash_option->setFixedWidth(150);
	hash_option->addItem("All Time");
	hash_option->addItem("1 Day");


	test_layout = new QVBoxLayout;
	test_layout->addWidget(test);

	hlayout = new QHBoxLayout;
	hlayout->addWidget(tweet_text);
	hlayout->addLayout(test_layout);

	final_layout = new QVBoxLayout;
	final_layout->addWidget(hash_option);
	final_layout->addLayout(hlayout);
	final_layout->addWidget(refresh_btn);

	setFixedWidth(800);
	setMinimumHeight(500);
	
	refresh();
	
	setLayout(final_layout);

}

HashWin::~HashWin(){}

void HashWin::fill_listwidget(){
	//if theres previous txt in it, erase it
	if(tweet_text->count() > 0){tweet_text->clear(); }

	//see who sent signal, get thier button txt, and locate tweets in map
	QObject * temp =  QObject::sender() ;
	std::vector<Tweet*> copy = htags->find(temp->objectName().toStdString())->second;

	//create comp obj and heapsort the tweet vector
	CompTweets lthan;
	heapsort(copy, lthan);

	//gets current qcombobox index to determine how to populate
	if(hash_option->currentIndex() == 0){
		for( int i=0; i<copy.size(); i++){
			tweet_text->addItem(QString::fromStdString(copy.at(i)->FullTweet()));
		}
	}
	else{
		//create datetime from a day ago and display tweets that are greater than it
		time_t now = time(0);
   		tm *ltm = localtime(&now);
		DateTime temp_date(1+ltm->tm_hour,1+ltm->tm_min,1+ltm->tm_sec,1900 + ltm->tm_year,1 + ltm->tm_mon, ltm->tm_mday-1);

		for( int i=0; i<copy.size(); i++){
			if(copy.at(i)->time() > temp_date){
				tweet_text->addItem(QString::fromStdString(copy.at(i)->FullTweet()));
			}
		}

	}
}

void HashWin::add_hashtag(std::string btnname, int size){
	//convert number to string
	std::ostringstream convert;
	convert << std::setfill('_') << std::left <<std::setw(25) << btnname <<  size;
	//create button text with #of tweets and hashtags
	QString btn_txt(convert.str().c_str());
	//btn_txt+= (" ) " +QString::fromStdString(btnname));
	//make buttone with text, connect , and then display it
	QPushButton* temp = new QPushButton(btn_txt);
	temp->setObjectName(QString::fromStdString(btnname));
	temp->setFlat(true);
	temp->setStyleSheet("text-align: left");
	connect(temp, SIGNAL(pressed()), this, SLOT(fill_listwidget()));
	test_layout->addWidget(temp);
}

void HashWin::refresh(){
	QLayoutItem *child;
	while ((child = test_layout->takeAt(0)) != 0)  {
		child->widget()->hide();
		test_layout->removeItem(child);
    	delete child;
	}

	std::vector< std::pair<std::string, std::vector<Tweet*> > > temp;
	for(std::map<std::string, std::vector<Tweet*> >::iterator it= htags->begin(); it!= htags->end(); it++){
		temp.push_back(std::make_pair(it->first , it->second));
	}

	CompMap temp_comp;
	heapsort(temp, temp_comp);
	int temp_int = temp.size();

	for (int i = 0; i<temp_int; i++){
		add_hashtag(temp.at(i).first, temp.at(i).second.size());
	}


}