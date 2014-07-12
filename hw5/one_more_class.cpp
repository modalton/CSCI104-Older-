#include "one_more_class.h"
#include <QString>

one_more_class::one_more_class(std::map<std::string, q_user*>& example): QWidget(){

		master_list = &example;

		stackedWidget = new QStackedWidget;


		user_select= new QComboBox;

		follow_select= new QComboBox;
		follow_button = new QPushButton("Follow");

//Populate combo boxes with appropriate stuff
		std::map<std::string,q_user*>::iterator it;
		for (it=example.begin(); it!=example.end(); ++it){
			user_win* temp= new user_win;
			temp->reinitialize(it->second, example);
			stackedWidget->addWidget(temp);
			user_select->addItem(QString::fromStdString(it->first));
			follow_select->addItem(QString::fromStdString(it->first));
    		//it->second->real_user->getFeed();
		}

		 connect(user_select, SIGNAL(activated(int)),stackedWidget, SLOT(setCurrentIndex(int)));
		 connect(follow_button, SIGNAL(clicked()),this, SLOT(add_follower()));


		top_bar = new QHBoxLayout;
		top_bar->addWidget(user_select);
		top_bar->addWidget(follow_select);
		top_bar->addWidget(follow_button);

		
		final= new QVBoxLayout;
		final->addLayout(top_bar);
		final->addWidget(stackedWidget);

		setLayout(final);

						}


void one_more_class::add_follower(){
	std::string p1 = user_select->currentText().toStdString();
	std::string p2 = follow_select->currentText().toStdString();

//	master_list.find(p1)->second->following_new(master_list.find(p2)->second);


	
}

one_more_class::~one_more_class(){}


