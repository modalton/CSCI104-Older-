#ifndef GUI_TWEET_H
#define GUI_TWEET_H

#include <QObject>
#include <QLabel>
#include <string>
#include <QString>



class gui_tweet : public QLabel // you can also try QMainWindow
{
	Q_OBJECT

	public:
		gui_tweet(std::string text);
		gui_tweet();
		void add_tweet(std::string text);
		QLabel* get_display();
		



	private:
	QString my_text;
	QLabel* display;


};

#endif