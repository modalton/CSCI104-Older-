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

	setup = new gui_tweet[10]; //change to dynamic!
	final_widget = new QListWidget;



	

}

void feed_widget::append_feed(int pos, std::string input){
	setup[pos].add_tweet(input);
	
	QListWidgetItem * temp = new QListWidgetItem();
	final_widget->addItem(temp);
	final_widget->setItemWidget(temp, setup[pos].get_display());

	//final_widget->visualItemRect(setup[pos].get_display()); //FYI if added in same place it still posts to QVBOX
}

