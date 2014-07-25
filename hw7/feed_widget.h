#ifndef FEED_WIDGET_H
#define FEED_WIDGET_H

#include <QObject>
#include <QLabel>
#include <string>
#include <QString>
#include <QListWidget>
#include <QVBoxLayout>
#include <vector>
#include "gui_tweet.h"


class feed_widget : public QListWidget // you can also try QMainWindow
{
	Q_OBJECT

	public:
	//THIS WIDGET CONTROLS MANIPULATING INPUT TEXT INTO 
	//QLISTWDIGET OF LABELS SO PICTURES CAN BE ADDED LATER

	feed_widget();
	void append_feed(std::string input);

	QListWidget* final_widget;

	

		



	private:
	QVBoxLayout * omg_qt_rules;
	std::vector<gui_tweet*> setup; 


};

#endif