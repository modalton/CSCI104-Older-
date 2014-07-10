#include "q_user.h"
#include <ctime>
#include <cstddef>
#include <time.h>
#include <string>


q_user::q_user(std::string name){
	real_user = new User(name);
	feed = new feed_widget;
}

q_user::q_user(){	
//	feed = new feed_widget;


	}

q_user::~q_user(){}


void q_user::new_tweet(std::string text){
	
	

	//make tweet for underlying user
   time_t now = time(0);
   tm *ltm = localtime(&now);

   DateTime* temp_date = new DateTime(1+ltm->tm_hour,1+ltm->tm_min,1+ltm->tm_sec,1900 + ltm->tm_year,1 + ltm->tm_mon, ltm->tm_mday);
   Tweet* made_tweet = new Tweet(real_user, *temp_date, text);
   
   // print various components of tm structure.
   std::cout << "Year: "<< 1900 + ltm->tm_year << std::endl;
   std::cout << "Month: "<< 1 + ltm->tm_mon<< std::endl;
   std::cout << "Day: "<<  ltm->tm_mday << std::endl;
   std::cout << "Time: "<< 1 + ltm->tm_hour << ":";
   std::cout << 1 + ltm->tm_min << ":";
   std::cout << 1 + ltm->tm_sec << std::endl;

 




}

void q_user::following_new(){

}
