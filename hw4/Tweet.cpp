#include "Tweet.h"

 Tweet::Tweet(User* user, DateTime& timer, std::string& text){
 	_poster=user;
 	_time= timer;
 	_text= text;

 	user->addTweet(this);
 	user->pushTweet(this);

 }

DateTime const & Tweet::time() const{return _time;}

std::string const & Tweet::text() const{ return _text;}


std::ostream& operator<<(std::ostream& os, const Tweet& t){
	os<< t.time() << " "<< (t._poster)->name() << " " << t.text() << "\n";
	return os;
}

