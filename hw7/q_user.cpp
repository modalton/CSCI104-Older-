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

}

q_user::q_user(){	

	}


q_user::~q_user(){}

//Next two functions are exactly as they sound
void q_user::app_feed(std::string text){
	feed->append_feed(text);
}

void q_user::app_mentions_feed(std::string text){
	mention_feed->append_feed(text);
}

void q_user::new_tweet(std::string text, std::map<std::string, q_user*> &master_list, std::map<std::string, std::vector<Tweet*> >& htags){


//GETS CURRENT TIME AND TURNS THIS AND TEXT INTO A DATE TIME AND TWEET
//AS WELL AS PERFORMING SCREENING FOR A @TWEET
//UPDATES THINGS ACCORDINGLY

   time_t now = time(0);
   tm *ltm = localtime(&now);

   DateTime temp_date(1+ltm->tm_hour,1+ltm->tm_min,1+ltm->tm_sec,1900 + ltm->tm_year,1 + ltm->tm_mon, ltm->tm_mday);
   Tweet* made_tweet = new Tweet(real_user, temp_date, text, master_list, true);

   std::set<std::string> temp_hashs = made_tweet->getHashTags();
   for( std::set<std::string>::iterator it = temp_hashs.begin(); it!= temp_hashs.end(); ++it){
		//if the hashtag has already been used in the map it updates or it creates a new entry then updates
			if(htags.find(*it)!= htags.end()){
				htags.find(*it)->second.push_back(made_tweet);
			}
			else{
				std::vector<Tweet*> temp_vector;
				temp_vector.push_back(made_tweet);
				htags.insert(std::pair<std::string, std::vector<Tweet*> >(*it, temp_vector) );
			}
		}


}

//populate the feeds on first initialization with sorted tweets
void q_user::reset_feed(){
	for(int i = real_user->tweets().size(); i != 0; i--){
		feed->append_feed(real_user->tweets().get(i-1)->FullTweet());
	}


	for(int i =real_user->mention_tweets().size(); i!=0; i--){
		mention_feed->append_feed(real_user->mention_tweets().get(i-1)->FullTweet());
	}

}


void q_user::following_new( q_user* two){
	if(this == two){return;}
	this->real_user->addFollowing(two->real_user);

}
