#include <QApplication>
#include "user_win.h"

#include "Set.h" 
#include "User.cpp"
#include "AList.h"
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <cstring>
#include "datetime.cpp"
#include "Tweet.cpp"
#include <cstddef>
#include "one_more_class.cpp"
#include "q_user.h"
#include <map>
#include <vector>



using namespace std;
int main(int argc, char *argv[]) {
	QApplication app(argc, argv); 

	string line;
	int members;
	map<string, q_user*> all_users;
	map<string, vector<Tweet*> > hashtag_tweets;


//try to open file
	ifstream file(argv[1]);  
		if(file.fail()){
			cout<<"Please input proper file\n";exit(1);
		} 
//get/check members int
	getline(file,line);
	stringstream ss(line); 
		if((ss>>members).fail()){
			cout<<"Please input proper file\n";exit(1);} 
			ss>>members;

	//for amount of members specified above we iterate and add them 
	//to our set of user pointers
	for(int i=0; i<members; i++){
		getline(file,line);
		istringstream split(line);
		
	//Test to see if name has integers int it. If so will exit the program
	string name;
		size_t test_pos= name.find_first_of("0123456789");
		if (test_pos!= string::npos || name == " ")
			{cout<<"Please input proper file\n";exit(1);}
		getline(split,name, ' ');

		q_user* bob= new q_user(name);
		all_users.insert(pair<string,q_user*>(name, bob));
	}
	file.close();

	//we reopen the file to go through again and add the friends
	//did this bc we don't want to instantiate anyone who isnt a user
	ifstream file1(argv[1]);
	getline(file1,line);
	for(int i=0; i<members; i++){

	//takes first part of the line to find guy with friends' name
	//aka person who we will be adding friends too
		getline(file1,line);
		istringstream split(line);

		string guywithfriends;
		getline(split,guywithfriends, ' ');
		

	//go through rest of line to add friends to aforementioned user
		string amigo;
		while(getline(split,amigo, ' ')){
					(*all_users.find(guywithfriends)).second->real_user->addFollowing((*all_users.find(amigo)).second->real_user);
					}
				}

	//parse through rest of the file (aka tweets)
	//set up a sscanf with fail check to read each part into datetime/tweet constructor
	//then assign each tweet to a user and push the tweet to thier followers(not in main from class functions)
	while(getline(file1,line)){
		int y,m,d,h,mn,s;
		char person[15];
		char content[141];
		sscanf(line.c_str(), "%d-%d-%d   %d:%d:%d  %14s %[^\n]",&y, &m, &d,&h,&mn,&s, &person[0], &content[0]);
		if(sscanf(line.c_str(), "%d-%d-%d   %d:%d:%d  %14s %[^\n]",&y, &m, &d,&h,&mn,&s, &person[0], &content[0]) != 8){
			cout<<"Please input proper file\n";exit(1);
		}

		string text = content;
		string tweeter = person;

		DateTime temp_date(h,mn,s,y,m,d);
		Tweet* made_tweet = new Tweet((*all_users.find(tweeter)).second->real_user, temp_date, text, all_users, false);

		//read through unique hashtags in new tweet 
		set<string> temp_hashs = made_tweet->getHashTags();
		for( set<string>::iterator it = temp_hashs.begin(); it!= temp_hashs.end(); ++it){
		//if the hashtag has already been used in the map it updates or it creates a new entry then updates
			if(hashtag_tweets.find(*it)!= hashtag_tweets.end()){
				hashtag_tweets.find(*it)->second.push_back(made_tweet);
			}
			else{
				vector<Tweet*> temp_vector;
				temp_vector.push_back(made_tweet);
				hashtag_tweets.insert(std::pair<string, vector<Tweet*> >(*it, temp_vector) );
			}
		}
				
															
									
								}


 

	

	one_more_class final(all_users, hashtag_tweets);
	final.show();


//causes the application to execute
    app.exec();

//deconstruct all users (users deconstruct thier tweets)
	map<string,q_user*>::iterator it;
	for(it = all_users.begin(); it!= all_users.end(); it++){
		delete it->second->real_user;
	}

}