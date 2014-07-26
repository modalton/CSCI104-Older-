#include "one_more_class.h"
#include <QString>

one_more_class::one_more_class(std::map<std::string, q_user*>& example, std::map<std::string, std::vector<Tweet*> >& htags): QWidget(){

		setWindowTitle("#Twitter");
//set pointers to global data
		master_list = &example;
		all_htags = &htags;
//stacked widget for user wins
		stackedWidget = new QStackedWidget;
//where user puts feed name
		input = new QLineEdit;

//combo boxes which will bee filled w users
		user_select= new QComboBox;
		user_select->setFixedWidth(80);
		follow_select= new QComboBox;
		follow_select->setFixedWidth(80);
//buttons for following,user swithc, and feed selection
		follow_button = new QPushButton("Follow");
		follow_button->setFixedWidth(70);
		feed_button = new QPushButton("Get Feeds");
		feed_button->setFixedWidth(80);
		user_button = new QPushButton("Change User");
		user_button->setFixedWidth(100);


//button for new window
		new_window = new QPushButton("Hashtags");
		new_window->setFixedWidth(80);


//Populate combo boxes with appropriate stuff
		std::map<std::string,q_user*>::iterator it;
		for (it=example.begin(); it!=example.end(); ++it){
			user_win* temp= new user_win;
			temp->reinitialize(it->second, example, htags);
			stackedWidget->addWidget(temp);
			user_select->addItem(QString::fromStdString(it->first));
			follow_select->addItem(QString::fromStdString(it->first));
    		
		}

//connect combo box to auto select and another three to call slots in this class
		 connect(user_button, SIGNAL(clicked()),this, SLOT(change_user()));
		 connect(follow_button, SIGNAL(clicked()),this, SLOT(add_follower()));
		 connect(feed_button, SIGNAL(clicked()),this, SLOT(make_feed()));
		 connect(new_window, SIGNAL(clicked()), this, SLOT(hashtag_window()));

//format layouts of all widgets
		top_bar = new QHBoxLayout;
		top_bar->addWidget(user_select);
		top_bar->addWidget(user_button);
		top_bar->addSpacing(400);
		top_bar->addWidget(follow_select);
		top_bar->addWidget(follow_button);

		bottom_bar = new QHBoxLayout;
		bottom_bar->addWidget(input);
		bottom_bar->addWidget(feed_button);

		
		final= new QVBoxLayout;
		final->addWidget(new_window);
		final->addLayout(top_bar);
		final->addWidget(stackedWidget);
		final->addLayout(bottom_bar);
		final->setSpacing(40);
		setFixedWidth(750);
		setMinimumHeight(650);
		setLayout(final);

		been_called = false;
						}

//takes button inputs and calls function to follow them 
void one_more_class::add_follower(){
	std::string p1 = user_select->currentText().toStdString();
	std::string p2 = follow_select->currentText().toStdString();

	std::map<std::string, q_user*>::iterator it;
 	it =master_list->find(user_select->currentText().toStdString());
 	q_user* main = it->second;
 	it =master_list->find(follow_select->currentText().toStdString());
 	q_user* following = it->second;

 	main->following_new(following);



	
}

void one_more_class::hashtag_window(){
	if(!been_called){
		hwindow = new HashWin(all_htags);
		been_called = true;
		}
	hwindow->show();
}

void one_more_class::change_user(){
	stackedWidget->setCurrentIndex(user_select->currentIndex());
}

void one_more_class::make_feed(){
	std::string filename = 	input->text().toStdString() + ".feed";
	std::ofstream output(filename.c_str());

	std::string users;
	Set<Tweet> all_tweets;
	AList<Tweet*>final_list;

	output<<master_list->size() << "\n";
	

	std::map<std::string,q_user*>::iterator it;
		for (it=master_list->begin(); it!=master_list->end(); ++it){
			q_user* temp = it->second;
			users+= temp->real_user->followingString();
			users+= "\n";

			//copy construct alist of each users tweets and add to a set (set keeps them unique & in order)
			AList<Tweet*> temp_list = temp->real_user->get_user_tweets();
			for(int i = 0; i<temp_list.size(); i++){
				all_tweets.add(*temp_list.get(i));
			}
		}

	output<<users;
//iterate through unique and ordered set of tweets to get final list
	std::set<Tweet>::iterator done;
		for(done=all_tweets.begin(); done!=all_tweets.end(); done++){
			Tweet really = *done;
			output<< really;
		}




//close file when were done with it
	output.close();


}

one_more_class::~one_more_class(){}


