#ifndef HASH_WIN_H
#define HASH_WIN_H

#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <string>
#include "Tweet.h"
#include "hsort.h"
#include <map>
#include <QString>
#include <QListWidget>
#include <QStackedWidget>
#include <QComboBox>
#include <ctime>
#include <time.h>
#include <sstream>
#include <iomanip>

class HashWin: public QWidget{
	Q_OBJECT

public:
	HashWin(std::map<std::string, std::vector<Tweet*> >* x);
	~HashWin();


public slots:
	void add_hashtag(std::string btnname, int size);
	void refresh();
	void fill_listwidget();



private:
	std::map<std::string, std::vector<Tweet*> >* htags; 
	QListWidget* tweet_text;
	QComboBox* hash_option;
	QPushButton* test;
	QPushButton* refresh_btn;
	QVBoxLayout* test_layout;
	QHBoxLayout* hlayout;
	QVBoxLayout* final_layout;


};

//Comparator class for comparing tweet*
struct CompTweets{
	bool operator()(const Tweet* A, const Tweet* B) {
		return (*A < *B) ;
	}
};

struct CompMap{
	bool operator()(const std::pair<std::string, std::vector<Tweet*> >&  A,
					const std::pair<std::string, std::vector<Tweet*> >& B){
		return (A.second.size() > B.second.size()) ;
	}
};




#endif