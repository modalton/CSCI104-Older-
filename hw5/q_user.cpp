#include "q_user.h"
#include <ctime>
#include <cstddef>
#include <time.h>
#include <string>


q_user::q_user(std::string name){
	real_user = new User(name);
	feed = new feed_widget;

	//add tweets from file to feed

}

q_user::q_user(){	
//	feed = new feed_widget;

	}


q_user::~q_user(){}


void q_user::new_tweet(std::string text){
	
	

	//make tweet for underlying user
   time_t now = time(0);
   tm *ltm = localtime(&now);

   DateTime* temp_date = new DateTime(1+ltm->tm_hour,1+ltm->tm_min,1+ltm->tm_sec,1900 + ltm->tm_year,1 + ltm->tm_mon, ltm->tm_mday);
   Tweet* made_tweet = new Tweet(real_user, *temp_date, text);
   
   feed->append_feed(made_tweet->FullTweet());
 

}

void q_user::reset_feed(){
	for(int i =0; i < real_user->feed.size(); i++){
		feed->append_feed(real_user->feed.get(i)->FullTweet());
	}
}


void q_user::following_new(){

}
