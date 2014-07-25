#ifndef USER_WIN_H
#define USER_WIN_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QComboBox>
#include <map>
#include "q_user.h"
#include "feed_widget.h"
#include <QStackedWidget>


class user_win : public QWidget // you can also try QMainWindow
{
	Q_OBJECT

	public:
		user_win(q_user* the_user);
		user_win();
		~user_win();
//change who the main user (q_user* is for this window)
		void reinitialize(q_user* maker, std::map<std::string, q_user*> &master_list, std::map<std::string, std::vector<Tweet*> >& htags);
		q_user* main_user;

	protected:
	
		

	private slots:
		void tweet_Click();
		void chng_feed_2mention();
		void chng_feed_2feed();
		

	private:
//layout is the final layout for this child widget
		QVBoxLayout *layout;

//post/switch feed buttons for this child
// flip bool is so the widget knows which to switch too
		QPushButton * post_tweet;
		QPushButton * switch_feeds;
		QPushButton * switch_feeds2;
	
//text box
		QPlainTextEdit * tweet_text;
//has both feed ontop of one another
		QStackedWidget* all_feeds;

//global data pointers
		std::map<std::string, q_user*>* master_list;
		std::map<std::string, std::vector<Tweet*> >* all_htags;

};

#endif