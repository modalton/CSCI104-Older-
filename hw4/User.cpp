//User::User(){delete;}

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

void User::addFollowing(User* u){ std::cout<<name() << "<- is following->" << u->name() <<"\n";
 this->user_following.add(u); 
}

void User::addFollower(User* u){ std::cout<<name() << " is followed by->" << u->name() <<"\n";
 this->user_followers.add(u); 
}

void User::addTweet(Tweet* T){user_tweets.insert(0,T); }

AList<Tweet*> User::tweets(){//return user_tweets;
}

void User::getFeed(){
	std::cout<<"USER: " << name()<<"\n";
	for(int i=0;i<user_tweets.size();i++){
		std::cout<<(user_tweets.get(i))->text()<<"\n";
	}
	std::cout<<"\n";
//need to return pointer to new one	
//	return user_tweets;
}