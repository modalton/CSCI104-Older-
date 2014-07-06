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
	setup = new gui_tweet[4];
	final_widget = new QVBoxLayout;

	setup[0].add_tweet("works before");
	final_widget->addWidget(setup[0].get_display());

	//setLayout(final_widget);
}

void feed_widget::append_feed(int pos, std::string input){
	setup[pos].add_tweet(input);
	final_widget->addWidget(setup[pos].get_display()); //FYI if added in same place it still posts to QVBOX
}