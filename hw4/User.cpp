//User::User(){delete;}

User::User(std::string name){
	username=name;
}

User::User(){
	//we aint found shit
}

std::string  User::name(){return username;}

bool User::operator==(const User& other) const{
	if(this->username == other.username){return true;}
	return false;
}

Set<User*> User::followers(){return followers;}
