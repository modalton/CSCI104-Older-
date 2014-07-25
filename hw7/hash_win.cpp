#include "hash_win.h"


HashWin::HashWin(std::map<std::string, std::vector<Tweet*> >* x){
	htags = x;
	test = new QPushButton("hello");
	connect(test, SIGNAL(clicked()), this, SLOT(refresh()));

	tweet_text = new QListWidget;

	test_layout = new QVBoxLayout;
	test_layout->addWidget(test);

	hlayout = new QHBoxLayout;

	hlayout->addWidget(tweet_text);
	hlayout->addLayout(test_layout);
	
	refresh();
	
	setLayout(hlayout);

}

HashWin::~HashWin(){}

void HashWin::fill_listwidget(){

//	tweet_text->clear();
	QObject * temp =  QObject::sender() ;
	std::vector<Tweet*> copy = htags->find(temp->objectName().toStdString())->second;
	for( int i=0; i<copy.size(); i++){
		tweet_text->addItem(QString::fromStdString(copy.at(i)->FullTweet()));
	}
}

void HashWin::add_hashtag(std::string btnname){
	QPushButton* temp = new QPushButton(QString::fromStdString(btnname));
	temp->setObjectName(QString::fromStdString(btnname));
	connect(temp, SIGNAL(pressed()), this, SLOT(fill_listwidget()));
	test_layout->addWidget(temp);
}

void HashWin::refresh(){
	for(std::map<std::string, std::vector<Tweet*> >::iterator it= htags->begin(); it!= htags->end(); it++){
		add_hashtag(it->first);
	}
}