#include "feed_widget.h"

/*
feed_widget::feed_widget(test_user* test){
	setup = new gui_tweet[3];
	final_widget = new QVBoxLayout;
	for(int i=0; i<3; i++){
		setup[i].add_tweet(test->stuffs[i]);
		final_widget->addWidget(setup[i].get_display());
	}
	setLayout(final_widget);
}*/

feed_widget::feed_widget(){
	omg_qt_rules = new QVBoxLayout;
	final_widget = new QListWidget;
	pos = 0;



	

}

void feed_widget::append_feed( std::string input){
	gui_tweet* text = new gui_tweet;
	text->add_tweet(input);
	setup.push_back(text);

	
	QListWidgetItem * temp = new QListWidgetItem();
	final_widget->insertItem(0,temp);
	final_widget->setItemWidget(temp, setup.back()->get_display());
	pos++;

	//final_widget->visualItemRect(setup[pos].get_display()); //FYI if added in same place it still posts to QVBOX
}

