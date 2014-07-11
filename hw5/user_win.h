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
		void change_user(q_user* new_q);
		void reinitialize(q_user* maker, std::map<std::string, q_user*> &master_list);
		q_user* main_user;

	protected:
	
		

	private slots:
		void tweet_Click();
		void chng_feed();
		

	private:

		QVBoxLayout *layout;

		QPushButton * post_tweet;

		QPushButton * switch_feeds;
		bool flip;

		QPlainTextEdit * tweet_text;

		QStackedWidget* all_feeds;


		std::map<std::string, q_user*>* master_list;

};

#endif