#include "gui_tweet.h"

gui_tweet::gui_tweet(std::string text){
	my_text = QString::fromStdString(text);

	display = new QLabel;
	display->setText(my_text);
}

QLabel* gui_tweet::get_display(){
	return display;
} 

gui_tweet::gui_tweet(){}

void gui_tweet::add_tweet(std::string text){
	my_text = QString::fromStdString(text);

	display = new QLabel;
	display->setText(my_text);
}


