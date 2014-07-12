#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "user_win.h"
#include <map>
#include <QStackedWidget>
#include <QLineEdit>
#include <fstream>

#ifndef ONE_MORE_CLASS_H
#define ONE_MORE_CLASS_H

class one_more_class : public QWidget{
	Q_OBJECT

public:
	one_more_class(std::map<std::string, q_user*>& example);
	~one_more_class();

public slots:
	void add_follower();
	void make_feed();


private:
	std::map<std::string, q_user*>* master_list;

	QStackedWidget* stackedWidget;

	QLineEdit* input;

	QComboBox* user_select;
	QComboBox* follow_select;

	QPushButton* follow_button;
	QPushButton* feed_button;

	QHBoxLayout* top_bar;
	QHBoxLayout* bottom_bar;
	QVBoxLayout* final;



};





#endif