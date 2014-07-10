#include <string>
#include <sstream>
#include "user_win.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <iostream>


using namespace std;

user_win::user_win(){}

user_win::user_win(q_user* the_user) : QWidget()
{
		main_user = the_user;

		//BUTTONS
		post_tweet = new QPushButton("Post Tweet");
		switch_feeds = new QPushButton("Switch Feeds");
		
		//TEXT BOX
		tweet_text = new QPlainTextEdit;

		//FEED
		//feed = new feed_widget;


	
		connect(post_tweet, SIGNAL(clicked()), this , SLOT(tweet_Click()));
	
	


		QVBoxLayout *layout = new QVBoxLayout;
		layout->addWidget(main_user->feed->final_widget); 
		layout->addWidget(switch_feeds);
		layout->addWidget(tweet_text);
		layout->addWidget(post_tweet);
		setLayout(layout);

	// connect clicked signal of each button to the right slot
}

void user_win::change_user(q_user* new_q){
	main_user = new_q;


}

void user_win::reinitialize(q_user* maker){
	main_user = maker;
	//BUTTONS
		post_tweet = new QPushButton("Post Tweet");
		switch_feeds = new QPushButton("Switch Feeds");
		
		//TEXT BOX
		tweet_text = new QPlainTextEdit;
	
		connect(post_tweet, SIGNAL(clicked()), this , SLOT(tweet_Click()));
	

		QVBoxLayout *layout = new QVBoxLayout;
		layout->addWidget(main_user->feed->final_widget); 
		layout->addWidget(switch_feeds);
		layout->addWidget(tweet_text);
		layout->addWidget(post_tweet);
		setLayout(layout);

}

user_win::~user_win()
{
	//delete ??;
}




void user_win::tweet_Click()
{
	main_user->new_tweet((tweet_text->toPlainText()).toStdString());
	//feed->append_feed( (tweet_text->toPlainText()).toStdString());
}

