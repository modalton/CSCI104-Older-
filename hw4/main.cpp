#include "Set.h"
#include "User.h"
#include "AList.h"
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <cstring>
#include "datetime.cpp"
#include "Tweet.cpp"



using namespace std;

int main(){

string line;
int members;
Set<User*> all_users;
ifstream file("twitter.dat");   //CHANGE TO ARGV/C
getline(file,line);

members = atoi(line.c_str());   //IF ATOI.fail

for(int i=0; i<members; i++){
	getline(file,line);
	istringstream split(line);

	string name;
	getline(split,name, ' ');
	User* bob= new User(name);
	all_users.add(bob);

	//for(string iterator; )
}
file.close();



ifstream file1("twitter.dat");
getline(file1,line);

for(int i=0; i<members; i++){


	getline(file1,line);
	istringstream split(line);

	string guywithfriends;
	getline(split,guywithfriends, ' ');
	int temp;
	int temp2;

	for(int k=0; k<members; k++){
			cout<< (*all_users.commonsense(k))->name() <<"\n";
			if(((*all_users.commonsense(k))->name()) == guywithfriends){
				 temp = k;
				 break;}}

	string amigo;
	while(getline(split,amigo, ' ')){
				for(int j=0; j<members;j++){
					if((*all_users.next())->name()==amigo){temp2 = all_users.fnum();
					(*all_users.commonsense(temp))->addFollowing((*all_users.commonsense(temp2)));
					(*all_users.commonsense(temp2))->addFollower((*all_users.commonsense(temp)));}
				}}}


while(getline(file1,line)){
	int y,m,d,h,mn,s;
	char person[15];
	char content[141];
	sscanf(line.c_str(), "%d-%d-%d   %d:%d:%d  %14s %[^\n]",&y, &m, &d,&h,&mn,&s, &person[0], &content[0]);

	string text = content;
	string tweeter = person;

	for(int i=0; i<members;i++){
		if((*all_users.commonsense(i))->name() == tweeter){
			DateTime* temp_date = new DateTime(h,mn,s,y,m,d);
			Tweet* made_tweet = new Tweet(*all_users.commonsense(i), *temp_date, text);
														}
								}
							}

for (int i = 0; i < members; ++i)
{
	(*all_users.commonsense(i))->getFeed();
	(*all_users.commonsense(i))->tweets();
}

}




