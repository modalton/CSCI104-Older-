#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "user_win.h"

#ifndef ONE_MORE_CLASS_H
#define ONE_MORE_CLASS_H

class one_more_class : public QWidget{
	Q_OBJECT

public:
	one_more_class(user_win* prev);
	~one_more_class();


private:
	QComboBox* user_select;
	QPushButton* user_button;

	QComboBox* follow_select;
	QPushButton* follow_button;

	QHBoxLayout* top_bar;
	QVBoxLayout* final;



};





#endif