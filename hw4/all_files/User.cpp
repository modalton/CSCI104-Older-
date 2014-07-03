//User::User(){delete;}
#include "User.h"
#include <fstream>
#include <cstring>

User::User(std::string name){
	username=name;
}

User::User(){
	username="nobody"; //EDIT OUT
}

std::string  User::name(){return username;}

bool User::operator==(const User& other) const{
	if(username == other.username){return true;}
	return false;
}

Set<User*> User::followers(){return user_followers;}

void User::addFollowing(User* u){ this->user_following.add(u);u->addFollower(this); }

void User::addFollower(User* u){ this->user_followers.add(u); }

void User::addTweet(Tweet* t){user_tweets.insert(0,t); }

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
	for (int i = 0; i < user_followers.size(); ++i)
	{	(*user_followers.commonsense(i))->updateFeed(t);
	}
}

AList<Tweet*> User::tweets(){return user_tweets; //WHY DID I NEED COPY CONSTRUCTOR/ = op FOR THIS 
}

void User::getFeed(){
	std::string filename = username + ".feed";
	std::ofstream output(filename.c_str());
	output<< username<< "\n";
	for(int i=0; i<feed.size(); i++){
		output << *(feed.get(i));
	}
}