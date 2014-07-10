#include "q_user.h"

q_user::q_user(std::string name):User(name){}

q_user::q_user(){	
	feed = new feed_widget;

	}

q_user::~q_user(){}


void q_user::new_tweet(std::string text){
	
	feed->append_feed(text);

}

void q_user::following_new(){

}
