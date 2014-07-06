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
		~user_win();

	protected:
		void closeEvent(QCloseEvent *event);

	private slots:
		void tweet_Click();
		void follow_Click();

	private:
		q_user* main_user;

		QPushButton * post_tweet;
		QPushButton * switch_feeds;
		QPushButton * follow_button;

		QComboBox * user_select;
		QComboBox * follow_select;

		QPlainTextEdit * tweet_text;
		
		feed_widget* feed;
};

#endif