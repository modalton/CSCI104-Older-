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
 

 }

std::string  User::name(){return username;}

bool User::operator==(const User& other) const{
	if(username == other.username){return true;}
	return false;
}

Set<User*> User::followers(){return user_followers;}

void User::addFollowing(User* u){ 
	if(user_following.find(u)!= user_following.end()){ return;}
	this->user_following.add(u);u->addFollower(this); }

void User::addFollower(User* u){ this->user_followers.add(u); }

void User::addTweet(Tweet* t){user_tweets.insert(0,t); }

void User::add_mentions_tweet(Tweet* t){
	int f_size = mention_feed.size();
	if(f_size==0){mention_feed.insert(0,t);}
	for (int i = 0; i < f_size; ++i)
		{
		if(mention_feed.get(i) < t){mention_feed.insert(i,t); break;}
		if(i == f_size-1){mention_feed.insert(f_size,t);}
	}
}

void User::updateFeed(Tweet* t){
	int f_size = feed.size();
	if(f_size==0){feed.insert(0,t);}
	for (int i = 0; i < f_size; ++i)
		{
		if(feed.get(i) < t){feed.insert(i,t); break;}
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

AList<Tweet*> User::tweets(){return feed; //WHY DID I NEED COPY CONSTRUCTOR/ = op FOR THIS 
}

AList<Tweet*> User::mention_tweets(){return mention_feed; //WHY DID I NEED COPY CONSTRUCTOR/ = op FOR THIS 
}

void User::getFeed(){
	std::string filename = username + ".feed";
	std::ofstream output(filename.c_str());
	output<< username<< "\n";
	for(int i=0; i<feed.size(); i++){
		output << *(feed.get(i));
	}
}

std::string User::getString(){
	std::string final ="\n\n" + username + " \n";
		for(int i=0; i<feed.size(); i++){
		final+= feed.get(i)->FullTweet();
		final += "\n";
	}
	return final;
}