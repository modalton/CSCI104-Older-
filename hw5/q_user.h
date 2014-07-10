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

	public slots:
		void new_tweet(std::string text);
		void following_new();


	private slots:


	private:
		User* real_user;

	


};

#endif