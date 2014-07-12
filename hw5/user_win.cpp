#include <string>
#include <sstream>
#include "user_win.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <iostream>




user_win::user_win(){}

user_win::~user_win()
{
	
}

user_win::user_win(q_user* the_user) : QWidget()
{
		main_user = the_user;

		//BUTTONS
		post_tweet = new QPushButton("Post Tweet");
		switch_feeds = new QPushButton("Switch Feeds");

		flip = true;
		
		//TEXT BOX
		tweet_text = new QPlainTextEdit;



		all_feeds = new QStackedWidget;
		all_feeds->addWidget(main_user->mention_feed->final_widget);
		all_feeds->addWidget(main_user->feed->final_widget);
		
		// connect clicked signal of each button to the right slot
		connect(post_tweet, SIGNAL(clicked()), this , SLOT(tweet_Click()));
		connect(switch_feeds, SIGNAL(clicked()), this , SLOT(chng_feed()));
	
	


		layout = new QVBoxLayout;
		layout->addWidget(all_feeds); 
		layout->addWidget(switch_feeds);
		layout->addWidget(tweet_text);
		layout->addWidget(post_tweet);
		setLayout(layout);


}



void user_win::reinitialize(q_user* maker, std::map<std::string, q_user*> &master_list){

	
	main_user = maker;
	main_user->reset_feed(master_list);

	this->master_list = &master_list;

		//BUTTONS
		post_tweet = new QPushButton("Post Tweet");
		post_tweet->setFixedWidth(200);
		switch_feeds = new QPushButton("Switch Feeds");
		switch_feeds->setFixedWidth(200);

		flip = true;
		
		//TEXT BOX
		tweet_text = new QPlainTextEdit;

		all_feeds = new QStackedWidget;
		all_feeds->addWidget(main_user->feed->final_widget);
		all_feeds->addWidget(main_user->mention_feed->final_widget);
		

	
		connect(post_tweet, SIGNAL(clicked()), this , SLOT(tweet_Click()));
		connect(switch_feeds, SIGNAL(clicked()), this , SLOT(chng_feed()));


		QVBoxLayout *layout = new QVBoxLayout;
		layout->addWidget(all_feeds); 
		layout->addWidget(switch_feeds);
		layout->addWidget(tweet_text);
		layout->addWidget(post_tweet);
		setLayout(layout);


}

void user_win::chng_feed(){
	if(flip){all_feeds->setCurrentIndex(1); flip = false;}
	else{all_feeds->setCurrentIndex(0); flip = true;}
}






void user_win::tweet_Click()
{
	main_user->new_tweet((tweet_text->toPlainText()).toStdString(), *master_list);

	
}

