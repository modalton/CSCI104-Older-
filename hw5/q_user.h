#ifndef Q_USER_H
#define Q_USER_H

#include <QObject>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include <vector>



class q_user : public QObject // you can also try QMainWindow
{
	Q_OBJECT

	public:
		q_user();
		~q_user();

	public slots:
		void new_tweet();
		void following_new();


	private slots:


	private:
	


};

#endif