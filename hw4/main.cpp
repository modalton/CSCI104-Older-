#include "Set.h"
#include "User.h"
#include "AList.h"
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <cstring>



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

cout<< *(all_users.commonsense(0))->name() << endl;
/*

ifstream file1("twitter.dat");
getline(file1,line);

for(int i=0; i<members; i++){
		//		for(int p=0; p<members; p++){cout<< "at " << p <<" "<< all_users.commonsense(p)->name()<<endl;}

	getline(file1,line);
	istringstream split(line);
	cout<<"\nON LINE " <<line<< endl;

	string guywithfriends;
	getline(split,guywithfriends, ' ');
	cout<<guywithfriends<< " GWF" << endl;
	int temp;
	int temp2;

	for(int k=0; k<members; k++){
			cout<< all_users.commonsense(k)->name() <<"\n";
			if(strcmp((all_users.commonsense(k)->name()).c_str(), guywithfriends.c_str())==false){
				 temp = k;
				 cout<< (all_users.commonsense(temp))->name() << " - should be line person.  " << temp <<endl; break;}}

	string amigo;
	while(getline(split,amigo, ' ')){
				for(int j=0; j<members;j++){
					if((all_users.next())->name()==amigo){temp2 = all_users.fnum();
						//cout<<"comparing "<< all_users.commonsense(temp2)->name() << " to "<< amigo << endl;
					(all_users.commonsense(temp))->addFollowing((all_users.commonsense(temp2)));}
				}}}


*/


}




