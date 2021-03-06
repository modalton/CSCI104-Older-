#include "Tweet.h"

Tweet::Tweet(){}



Tweet::Tweet(const Tweet& other){
	_poster = other._poster;
	_time = other._time;
	_text= other._text;
}

 Tweet::Tweet(User* user, DateTime& timer, std::string& text){
 	_poster=user;
 	_time= timer;
 	_text= text;

 	

 	user->addTweet(this);
 	_poster->pushTweet(this);


 }

//constructor that can access q_user feeds 
 Tweet::Tweet(User* user, DateTime& timer, std::string& text, std::map<std::string, q_user*>& master_list, bool realtime){
 	_poster=user;
 	_time= timer;
 	_text= text;

 	spliceHashtags();

 	if(text.find('@')==0){
		std::istringstream split(text);
		std::string name;
		getline(split,name, ' ');
		

		std::string real_name = name.substr(1);
		//if its a real user after @
		if(master_list.find(real_name)!= master_list.end())
			{//add a mentions to user
			 (master_list.find(real_name))->second->real_user->add_mentions_tweet(this);
			 //see if mutual followers
			 if((master_list.find(real_name))->second->real_user->mutualFriend(user)){
			 	master_list.find(real_name)->second->real_user->updateFeed(this);
			 	user->updateFeed(this);
			 }
			 if(realtime){
					 //update mentioned q_user mention FEED
					 (master_list.find(real_name))->second->app_mentions_feed(this->FullTweet());
					 
					 //updates feed if mutal followers
					 if((master_list.find(real_name))->second->real_user->mutualFriend(user)){
						 //update mentioned q users FEED	
						 (master_list.find(real_name))->second->app_feed(this->FullTweet());
						 //update tweeters FEED
						 (master_list.find(user->name()))->second->app_feed(this->FullTweet());}}
			 user->addTweet(this);
			 return;
			}
		}

//If its realtime (AKA gui running) we can go ahead and add to feed. we dont need to sort&pull
	if(realtime){ master_list.find(user->name())->second->app_feed(this->FullTweet());}

	if(realtime){
			std::set<User*>::iterator it;
		 	for(it = user->user_followers.begin(); it != user->user_followers.end();it++ ){
			 		User* p = *it;
			 		std::map<std::string, q_user*>::iterator joke;
			 		joke =master_list.find(p->name());
			 		q_user* awful = joke->second;
			 		awful->feed->append_feed(this->FullTweet());
		 }


 	}
 //use old user class function to push to friends underlying data where it will be sorted
 		user->addTweet(this);
 		user->pushTweet(this);


		

	}
 

void Tweet::spliceHashtags(){
	std::size_t found = _text.find_first_of("#");
	  while (found!=std::string::npos)
	  {
	    std::istringstream splice(_text.substr(found+1));
		std::string hash;
		getline(splice,hash, ' ');
	    found=_text.find_first_of("#",found+hash.length());
	    _hashtags.insert(hash);
	  }

	  
}

std::set<std::string> Tweet::getHashTags(){
	return _hashtags;
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

