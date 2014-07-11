#ifndef Q_USER_H
#define Q_USER_H

#include <QObject>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include "User.h"
#include "feed_widget.h"



class q_user : public QObject  // you can also try QMainWindow
{
	Q_OBJECT

	public:
		q_user(std::string name);
		q_user();
		~q_user();
		feed_widget* feed;
		feed_widget* mention_feed;
		User* real_user;
		void app_feed(std::string text);
		void app_mentions_feed(std::string text);
	public slots:
		void new_tweet(std::string text, std::map<std::string, q_user*> &master_list);
		void following_new();
		void reset_feed();



	private slots:


	private:
		

	


};

#endif