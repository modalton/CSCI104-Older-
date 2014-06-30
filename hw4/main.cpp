#include "Set.h"
#include "User.h"
#include "AList.h"
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <vector>



using namespace std;

int main(){

string line;
int members;
Set<User> all_users;
ifstream file("twitter.dat");   //CHANGE TO ARGV/C
getline(file,line);

members = atoi(line.c_str());   //IF ATOI.fail

for(int i=0; i<members; i++){
	getline(file,line);
	istringstream split(line);

	string name;
	getline(split,name, ' ');
	cout <<name << endl;
	all_users.add(name);

	//for(string iterator; )
}
file.close();


ifstream file1("twitter.dat");
getline(file1,line);

for(int i=0; i<members; i++){
	getline(file1,line);
	istringstream split(line);

	string amigo;
	(getline(split,amigo, ' ');

	while(getline(split,amigo, ' ')){ for(int i=0; i<members; i++){if(all_users[i].name()==amigo){cout<<"aloha"<<endl;} }

	//for(string iterator; )
}




}