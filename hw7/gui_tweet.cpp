#include "gui_tweet.h"


gui_tweet::gui_tweet(std::string text){
	my_text = QString::fromStdString(text);

	display = new QLabel;
	display->setText(my_text);
}

QLabel* gui_tweet::get_display(){
	return display;
} 

gui_tweet::gui_tweet(){
	display = new QLabel;
}

void gui_tweet::add_tweet(std::string text){
	QString my_text = QString::fromStdString(text);

	display->setText(my_text);
	
}


