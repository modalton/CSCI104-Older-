#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "user_win.h"
#include <map>
#include <QStackedWidget>

#ifndef ONE_MORE_CLASS_H
#define ONE_MORE_CLASS_H

class one_more_class : public QWidget{
	Q_OBJECT

public:
	one_more_class(std::map<std::string, q_user*>& example);
	~one_more_class();

public slots:
	void add_follower();


private:
	std::map<std::string, q_user*>* master_list;

	QStackedWidget* stackedWidget;


	QComboBox* user_select;

	QComboBox* follow_select;
	QPushButton* follow_button;

	QHBoxLayout* top_bar;
	QVBoxLayout* final;



};





#endif