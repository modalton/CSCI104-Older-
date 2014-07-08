#ifndef FEED_WIDGET_H
#define FEED_WIDGET_H

#include <QObject>
#include <QLabel>
#include <string>
#include <QString>
#include <QListWidget>
#include <QVBoxLayout>
#include "gui_tweet.h"


class feed_widget : public QListWidget // you can also try QMainWindow
{
	Q_OBJECT

	public:
	//feed_widget(test_user* test);
	feed_widget();
	void append_feed(int pos, std::string input);

	QListWidget* final_widget;

	

		



	private:
	QVBoxLayout * omg_qt_rules;
	gui_tweet* setup; //change to dyamic in .cpp


};

#endif