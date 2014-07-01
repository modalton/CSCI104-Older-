//User::User(){delete;}

User::User(std::string name){
	username=name;
}

User::User(){
	username="nobody"; //EDIT OUT
}

std::string  User::name(){return username;}

bool User::operator==(const User& other) const{
	if(this->username == other.username){return true;}
	return false;
}

Set<User*> User::followers(){return user_followers;}

void User::addFollowing(User* u){ std::cout<<name() << "<- is following->" << u->name() <<"\n";
 //this->user_followers.add(u); 
}
