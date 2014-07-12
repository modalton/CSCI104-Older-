#include "q_user.h"
#include <ctime>
#include <cstddef>
#include <time.h>
#include <string>
#include <sstream>



q_user::q_user(std::string name){
	real_user = new User(name);
	feed = new feed_widget;
	mention_feed = new feed_widget;

	//add tweets from file to feed

}

q_user::q_user(){	
//	feed = new feed_widget;

	}


q_user::~q_user(){}

//Next two functions are exactly as they sound
void q_user::app_feed(std::string text){
	feed->append_feed(text);
}

void q_user::app_mentions_feed(std::string text){
	mention_feed->append_feed(text);
}

void q_user::new_tweet(std::string text, std::map<std::string, q_user*> &master_list){


//GETS CURRENT TIME AND TURNS THIS AND TEXT INTO A DATE TIME AND TWEET
//AS WELL AS PERFORMING SCREENING FOR A @TWEET
//UPDATES THINGS ACCORDINGLY

   time_t now = time(0);
   tm *ltm = localtime(&now);

   DateTime* temp_date = new DateTime(1+ltm->tm_hour,1+ltm->tm_min,1+ltm->tm_sec,1900 + ltm->tm_year,1 + ltm->tm_mon, ltm->tm_mday);
   Tweet* made_tweet = new Tweet(real_user, *temp_date, text);

//check for @ mention tweets
   if(text.find('@')==0){
		std::istringstream split(text);
		std::string name;
		getline(split,name, ' ');
		

		std::string real_name = name.substr(1);
		if(master_list.find(real_name)!= master_list.end())
			{(master_list.find(real_name))->second->real_user->add_mentions_tweet(made_tweet);
			 (master_list.find(real_name))->second->app_mentions_feed(made_tweet->FullTweet());
			 (master_list.find(real_name))->second->app_feed(made_tweet->FullTweet());
			  feed->append_feed(made_tweet->FullTweet());return;
			}
		

	}

	
 	//find whos makeing the tweet and call functions appropriatly
 	std::set<User*>::iterator it;
 	for(it = real_user->user_followers.begin(); it != real_user->user_followers.end();it++ ){
 		User* p = *it;
 		std::map<std::string, q_user*>::iterator joke;
 		joke =master_list.find(p->name());
 		q_user* awful = joke->second;
 		awful->feed->append_feed(made_tweet->FullTweet());
 	}


   
   feed->append_feed(made_tweet->FullTweet());

 

}

void q_user::reset_feed(std::map<std::string, q_user*> &master_list){
	for(int i =0; i < real_user->tweets().size(); i++){
		feed->append_feed(real_user->tweets().get(i)->FullTweet());
	}


	for(int i =0; i < real_user->mention_tweets().size(); i++){
		feed->append_feed(real_user->mention_tweets().get(i)->FullTweet());
	}


}


void q_user::following_new( q_user* two){
	if(this == two){return;}
	this->real_user->addFollowing(two->real_user);

}
