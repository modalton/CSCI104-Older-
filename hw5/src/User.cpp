//User::User(){delete;}
#include "User.h"
#include <fstream>
#include <cstring>

User::User(std::string name){
	username=name;
}

User::User(){
	
}

 User::~User(){
 	int temp = user_tweets.size();
 	for(int i = 0; i< temp; i++){
 		delete user_tweets.get(i);
 	}

 }

std::string  User::name(){return username;}

bool User::operator==(const User& other) const{
	if(username == other.username){return true;}
	return false;
}

Set<User*> User::followers(){return user_followers;}

Set<User*> User::following(){return user_following;}

void User::addFollowing(User* u){ 
	if(user_following.find(u)!= user_following.end()){ return;}
	this->user_following.add(u);u->addFollower(this); }

void User::addFollower(User* u){ this->user_followers.add(u); }

void User::addTweet(Tweet* t){	
	int f_size = user_tweets.size();
	if(f_size==0){user_tweets.insert(0,t);}
	for (int i = 0; i < f_size; ++i)
		{
		if(*user_tweets.get(i) < *t){user_tweets.insert(i,t); break;}
		if(i == f_size-1){user_tweets.insert(f_size,t);}
	}}

void User::add_mentions_tweet(Tweet* t){
	int f_size = mention_feed.size();
	if(f_size==0){mention_feed.insert(0,t);}
	for (int i = 0; i < f_size; ++i)
		{
		if(*mention_feed.get(i) < *t){mention_feed.insert(i,t); break;}
		if(i == f_size-1){mention_feed.insert(f_size,t);}
	}
}

void User::updateFeed(Tweet* t){
	int f_size = feed.size();
	if(f_size==0){feed.insert(0,t);}
	for (int i = 0; i < f_size; ++i)
		{
		if(*feed.get(i) < *t){feed.insert(i,t); break;}
		if(i == f_size-1){feed.insert(f_size,t);}
	}

}

void User::pushTweet(Tweet* t){
	updateFeed(t);
	std::set<User*>::iterator myIterator;
	for(myIterator = user_followers.begin(); myIterator != user_followers.end(); myIterator++)
		{	User* temp = *myIterator;
			temp->updateFeed(t);
	}
}

AList<Tweet*> User::tweets(){return feed; 
}

AList<Tweet*> User::get_user_tweets(){return user_tweets;
}

AList<Tweet*> User::mention_tweets(){return mention_feed; 
}

void User::getFeed(){
	std::string filename = username + ".feed";
	std::ofstream output(filename.c_str());
	output<< username<< "\n";
	for(int i=0; i<feed.size(); i++){
		output << *(feed.get(i));
	}
}

std::string User::followingString(){
	std::string output = name() + " ";
	std::set<User*>::iterator it;
		 	for(it = user_following.begin(); it != user_following.end();it++ ){
		 			User* temp = *it;
			 		output += temp->name();
			 		output+= " ";
			 	}


	return output;
}

bool User::mutualFriend(User* other){
	if((user_followers.find(other) != user_followers.end()) && (user_following.find(other) != user_following.end() ))
		{return true;}
	else {return false;}

	}


std::string User::getString(){
	std::string final ="\n\n" + username + " \n";
		for(int i=0; i<feed.size(); i++){
		final+= feed.get(i)->FullTweet();
		final += "\n";
	}
	return final;
}