#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "user_win.h"
#include "hash_win.h"
#include "Tweet.h"
#include <map>
#include <QStackedWidget>
#include <QLineEdit>
#include <fstream>

#ifndef ONE_MORE_CLASS_H
#define ONE_MORE_CLASS_H

class one_more_class : public QWidget{
	Q_OBJECT

//MOST IMPORTANT AS WELL AS EASIEST TO UNDERSTAND CLASS
//TAKES IN MAP OF ALL USERS AND CALLS DOWN TO ALL CHILD WIDGETS
//TO MAKE THE FINAL GUI WIDGET. BUTTONS CONNECT DIFFERENT SIGNALS
//SLOTS BETWEEN THESE CHILDREN
public:
	one_more_class(std::map<std::string, q_user*>& example, std::map<std::string, std::vector<Tweet*> >& htags);
	~one_more_class();  

public slots:
//if it can do so, it will add an unfollowed person to the slected
//persons followers
	void add_follower();
//creates the final mega feed for everyone
	void make_feed();
//as it sounds
	void change_user();

	void hashtag_window();


private:
	std::map<std::string, q_user*>* master_list;
	std::map<std::string, std::vector<Tweet*> >* all_htags;
//keeps all the userwins
	QStackedWidget* stackedWidget;
//to get feed file name
	QLineEdit* input;

//buttons and respective comboboxs
	QComboBox* user_select;
	QComboBox* follow_select;

	QPushButton* follow_button;
	QPushButton* feed_button;
	QPushButton* user_button;

//adds it altogether in final and sets it as layout
	QHBoxLayout* top_bar;
	QHBoxLayout* bottom_bar;
	QVBoxLayout* final;

//QPushbutton for new window
	QPushButton* new_window;

//Pointer to the hash_win button creates
	HashWin* hwindow;
	bool been_called;



};





#endif