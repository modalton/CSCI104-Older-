#include "Tweet.h"


 Tweet::Tweet(User* user, DateTime& timer, std::string& text){
 	_poster=user;
 	_time= timer;
 	_text= text;



 //	std::map<std::string,q_user*>::iterator it;
//		for (it=example.begin(); it!=example.end(); ++it){

//		}

//make a seqerate function and call it in upper func




	/*	size_t test_pos= name.find_first_of("@");
		if (test_pos==0)
			{cout<< name <<" buthoole\n";} */

			
		

 	

 	user->addTweet(this);
 	_poster->pushTweet(this);


 }

 

DateTime const & Tweet::time() const{return _time;}

std::string const & Tweet::text() const{ 
	return _text;}

std::string Tweet::FullTweet(){
	std::string temp;
	temp = _poster->name() + " " + _time.DateTime_string() + " " + _text ;
	return temp;
}


std::ostream& operator<<(std::ostream& os, const Tweet& t){
	os<< t.time() << " "<< (t._poster)->name() << " " << t.text() << "\n";
	return os;
}

