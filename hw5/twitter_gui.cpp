#include <QApplication>
#include "user_win.h"


int main(int argc, char *argv[]) {
	QApplication app(argc, argv);  

	q_user* temp = new q_user;
	user_win window(temp);

	window.setWindowTitle("Count Words");
	window.show();

	return app.exec();
}