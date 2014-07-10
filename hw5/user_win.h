#ifndef USER_WIN_H
#define USER_WIN_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QComboBox>
#include "q_user.h"
#include "feed_widget.h"

class user_win : public QWidget // you can also try QMainWindow
{
	Q_OBJECT

	public:
		user_win(q_user* the_user);
		user_win();
		~user_win();
		void change_user(q_user* new_q);
		void reinitialize(q_user* maker);

	protected:
	
		

	private slots:
		void tweet_Click();
		

	private:
		q_user* main_user;

		QPushButton * post_tweet;
		QPushButton * switch_feeds;

		QPlainTextEdit * tweet_text;
		
		feed_widget* feed;
};

#endif