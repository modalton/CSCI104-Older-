#include "Tweet.h"

 Tweet::Tweet(User* user, DateTime& timer, std::string& text){
 	_poster=user;
 	_time= timer;
 	_text= text;

 	user->addTweet(this);

 }

DateTime const & Tweet::time() const{return _time;}

std::string const & Tweet::text() const{ return _text;}