#ifndef HASH_WIN_H
#define HASH_WIN_H

#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <string>
#include "Tweet.h"
#include <map>
#include <QString>
#include <QListWidget>
#include <QStackedWidget>

class HashWin: public QWidget{
	Q_OBJECT

public:
	HashWin(std::map<std::string, std::vector<Tweet*> >* x);
	~HashWin();


public slots:
	void add_hashtag(std::string btnname);
	void refresh();
	void fill_listwidget();


private:
	std::map<std::string, std::vector<Tweet*> >* htags; 
	QListWidget* tweet_text;
	QPushButton* test;
	QVBoxLayout* test_layout;
	QHBoxLayout* hlayout;





};




#endif