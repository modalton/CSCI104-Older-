#include "one_more_class.h"
#include <QString>

one_more_class::one_more_class(std::map<std::string, q_user*>& example): QWidget(){

		master_list = &example;
//stacked widget for user wins
		stackedWidget = new QStackedWidget;
//where user puts feed name
		input = new QLineEdit;

//combo boxes which will bee filled w users
		user_select= new QComboBox;
		follow_select= new QComboBox;
//buttons for following and feed selection
		follow_button = new QPushButton("Follow");
		feed_button = new QPushButton("Get Feeds");

//Populate combo boxes with appropriate stuff
		std::map<std::string,q_user*>::iterator it;
		for (it=example.begin(); it!=example.end(); ++it){
			user_win* temp= new user_win;
			temp->reinitialize(it->second, example);
			stackedWidget->addWidget(temp);
			user_select->addItem(QString::fromStdString(it->first));
			follow_select->addItem(QString::fromStdString(it->first));
    		
		}

//connect combo box to auto select and another two to call slots in this class
		 connect(user_select, SIGNAL(activated(int)),stackedWidget, SLOT(setCurrentIndex(int)));
		 connect(follow_button, SIGNAL(clicked()),this, SLOT(add_follower()));
		 connect(feed_button, SIGNAL(clicked()),this, SLOT(make_feed()));

//format layouts of all widgets
		top_bar = new QHBoxLayout;
		top_bar->addWidget(user_select);
		top_bar->addWidget(follow_select);
		top_bar->addWidget(follow_button);

		bottom_bar = new QHBoxLayout;
		bottom_bar->addWidget(input);
		bottom_bar->addWidget(feed_button);

		
		final= new QVBoxLayout;
		final->addLayout(top_bar);
		final->addWidget(stackedWidget);
		final->addLayout(bottom_bar);
		setLayout(final);

						}


void one_more_class::add_follower(){
	std::string p1 = user_select->currentText().toStdString();
	std::string p2 = follow_select->currentText().toStdString();

	std::map<std::string, q_user*>::iterator it;
 	it =master_list->find(user_select->currentText().toStdString());
 	q_user* main = it->second;
 	it =master_list->find(follow_select->currentText().toStdString());
 	q_user* following = it->second;

 	main->following_new(following);

//	master_list.find(p1)->second->following_new(master_list.find(p2)->second);


	
}

void one_more_class::make_feed(){
	std::string filename = 	input->text().toStdString() + ".feed";
	std::ofstream output(filename.c_str());

	std::string file;
	std::map<std::string,q_user*>::iterator it;
		for (it=master_list->begin(); it!=master_list->end(); ++it){
			q_user* temp = it->second;
			file+= temp->real_user->getString();
		}

	output<< file ;
	output.close();


}

one_more_class::~one_more_class(){}


