#include "one_more_class.h"
#include <QString>

one_more_class::one_more_class(std::map<std::string, q_user*>& example): QWidget(){

		master_list = &example;

		stackedWidget = new QStackedWidget;


		user_select= new QComboBox;
		user_button= new QPushButton("Go");

		follow_select= new QComboBox;
		follow_button = new QPushButton("Follow");

//Populate combo boxes with appropriate stuff
		std::map<std::string,q_user*>::iterator it;
		for (it=example.begin(); it!=example.end(); ++it){
			user_win* temp= new user_win;
			temp->reinitialize(it->second, example);
			stackedWidget->addWidget(temp);
			user_select->addItem(QString::fromStdString(it->first));
    		//it->second->real_user->getFeed();
		}

		 connect(user_select, SIGNAL(activated(int)),stackedWidget, SLOT(setCurrentIndex(int)));


		top_bar = new QHBoxLayout;
		top_bar->addWidget(user_select);
		top_bar->addWidget(user_button);
		top_bar->addWidget(follow_select);
		top_bar->addWidget(follow_button);

		
		final= new QVBoxLayout;
		final->addLayout(top_bar);
		final->addWidget(stackedWidget);

		setLayout(final);

						}


void one_more_class::change_user_box(){
	std::string chng_to = (user_select->currentText()).toStdString();
	std::cout << chng_to << "\n";
	stackedWidget->setCurrentIndex(1);
//	window->change_user((master_list->find(chng_to))->second);

}

one_more_class::~one_more_class(){}


