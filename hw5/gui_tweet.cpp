#include "gui_tweet.h"


gui_tweet::gui_tweet(std::string text){
	my_text = QString::fromStdString(text);

	display = new QListWidgetItem;
	display->setText(my_text);
}

QListWidgetItem* gui_tweet::get_display(){
	return display;
} 

gui_tweet::gui_tweet(){
	display = new QListWidgetItem;
}

void gui_tweet::add_tweet(std::string text){
	QString my_text = QString::fromStdString(text);

	display->setText(my_text);
	
}


