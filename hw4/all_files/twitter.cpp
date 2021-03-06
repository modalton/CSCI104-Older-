#include "Set.cpp"
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



using namespace std;

int main(int argc, char* argv[]){

string line;
int members;
Set<User*> all_users;
ifstream file(argv[1]);   
if(file.fail()){cout<<"Please input proper file\n";exit(1);}
getline(file,line);

//read first line to see how many memebers 
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

	User* bob= new User(name);
	all_users.add(bob);
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
	int temp;
	int temp2;

//go through all_users to find corresponding user
	for(int k=0; k<members; k++){
			if(((*all_users.commonsense(k))->name()) == guywithfriends){
				 temp = k;
				 break;}}

//go through rest of line to add friends to aforementioned user
	string amigo;
	while(getline(split,amigo, ' ')){
				for(int j=0; j<members;j++){
					if((*all_users.next())->name()==amigo){temp2 = all_users.fnum();
					(*all_users.commonsense(temp))->addFollowing((*all_users.commonsense(temp2)));}
				}}}

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

	for(int i=0; i<members;i++){
		if((*all_users.commonsense(i))->name() == tweeter){
			DateTime* temp_date = new DateTime(h,mn,s,y,m,d);
			Tweet* made_tweet = new Tweet(*all_users.commonsense(i), *temp_date, text);
			made_tweet->PushTweet();

														}
								}
							}


}




