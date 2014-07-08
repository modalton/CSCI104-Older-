#include <string>
#include <sstream>
#include "user_win.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <iostream>


using namespace std;

user_win::user_win(q_user* the_user) : QWidget()
{
		main_user = the_user;

		//BUTTONS
		post_tweet = new QPushButton("Post Tweet");
		switch_feeds = new QPushButton("Switch Feeds");
		follow_button = new QPushButton("Follow");
		//TEXT BOX
		tweet_text = new QPlainTextEdit;
		//COMBO BOX
		user_select = new QComboBox();
		follow_select= new QComboBox();
		//FEED
		feed = new feed_widget;


	
		connect(post_tweet, SIGNAL(clicked()), this , SLOT(tweet_Click()));
		connect(follow_button, SIGNAL(clicked()), this , SLOT(follow_Click()));
	

		QHBoxLayout *topbar = new QHBoxLayout;
		topbar->addWidget(user_select);
		topbar->addWidget(follow_select);
		topbar->addWidget(follow_button);

		QVBoxLayout *layout = new QVBoxLayout;
		layout->addLayout(topbar);
		layout->addWidget(feed->final_widget); 
		std::cout << feed->final_widget;
		layout->addWidget(switch_feeds);
		layout->addWidget(tweet_text);
		layout->addWidget(post_tweet);
		setLayout(layout);

	// connect clicked signal of each button to the right slot
}

user_win::~user_win()
{
	//delete ??;
}

void user_win::closeEvent(QCloseEvent *event)
{
	if (true /* is it ok to close the window ? */)
	{
		// save data
		event->accept();
	}
	else // otherwise
	{
		event->ignore();
	}
}

void user_win::tweet_Click()
{
	main_user->new_tweet();
	feed->append_feed(0, (tweet_text->toPlainText()).toStdString());
}

void user_win::follow_Click()
{
	main_user->following_new();
}
