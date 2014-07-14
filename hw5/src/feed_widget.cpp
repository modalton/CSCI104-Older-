#include "feed_widget.h"


feed_widget::feed_widget(){
	omg_qt_rules = new QVBoxLayout;
	final_widget = new QListWidget;




	

}

void feed_widget::append_feed( std::string input){
	gui_tweet* text = new gui_tweet;
	text->add_tweet(input);
	setup.push_back(text);

	
	QListWidgetItem * temp = new QListWidgetItem();
	final_widget->insertItem(0,temp);
	final_widget->setItemWidget(temp, setup.back()->get_display());


	
}

