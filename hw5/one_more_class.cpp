#include "one_more_class.h"

one_more_class::one_more_class(user_win* prev): QWidget(){

		QComboBox* user_select= new QComboBox;
		QPushButton* user_button= new QPushButton("Go");

		QComboBox* follow_select= new QComboBox;
		QPushButton* follow_button = new QPushButton("Follow");

		QHBoxLayout* top_bar = new QHBoxLayout;
		top_bar->addWidget(user_select);
		top_bar->addWidget(user_button);
		top_bar->addWidget(follow_select);
		top_bar->addWidget(follow_button);

		QVBoxLayout* final= new QVBoxLayout;
		final->addLayout(top_bar);
		final->addWidget(prev);

		setLayout(final);

						}

one_more_class::~one_more_class(){}


