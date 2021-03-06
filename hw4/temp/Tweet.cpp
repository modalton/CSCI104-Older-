#include "Tweet.h"

 Tweet::Tweet(User* user, DateTime& timer, std::string& text){
 	_poster=user;
 	_time= timer;
 	_text= text;

 	user->addTweet(this);

 }

DateTime const & Tweet::time() const{return _time;}

std::string const & Tweet::text() const{ return _text;}

void Tweet::PushTweet(){
	_poster->pushTweet(this);
}


std::ostream& operator<<(std::ostream& os, const Tweet& t){
	os<< t.time() << " "<< (t._poster)->name() << " " << t.text() << "\n";
	return os;
}

