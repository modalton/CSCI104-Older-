#ifndef FEED_WIDGET_H
#define FEED_WIDGET_H

#include <QObject>
#include <QLabel>
#include <string>
#include <QString>
#include <QVBoxLayout>
#include "gui_tweet.h"


class feed_widget : public QWidget // you can also try QMainWindow
{
	Q_OBJECT

	public:
	//feed_widget(test_user* test);
	feed_widget();
	void append_feed(int pos, std::string input);
	QVBoxLayout* final_widget;
		



	private:
	//test_user* my_guy;
	
	gui_tweet* setup;


};

#endif