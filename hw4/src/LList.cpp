#include <iostream>
#include <stdexcept>
template <class T>
 Item<T>::Item(){}   // constructor

template <class T>
 Item<T>::Item(Item<T> &p){prev = &p;}   // constructor

 template <class T>
 Item<T>::~Item(){
 }   // deconstructor

template <class T>
 LList<T>::LList (){head = new Item<T>;}   // constructor

template <class T>
 LList<T>::~LList (){
//while loop goes through and deletes node from end until null
 		while(head!=NULL){
 			Item<T>* temp = head;
 			head = head->next;
			delete temp; 	
			} 
			

 }  // destructor

template <class T>
int LList<T>::size() const{
	int counter = 0;
	Item<T>* temp = head;
	while(temp->next!=NULL){
		counter++;
		temp = temp->next;
}
	

	return counter; 

}
template <class T>
void LList<T>::insert (int position, const T & val){
	
		if(position> this->size() || position < 0)
		{throw std::out_of_range("void LList<T>::insert (int position, const T & val)");}
		if(position == 0 && head->next==NULL){ head->next = new Item<T>(*head); head->next->next = NULL; head->next->value = val; return;}
		if(position >= 0){
			//iterate to insert position
			Item<T>* temp = head;
			for(int i=0; i<position; i++){temp = temp->next;}
			
			//create new item+value
			Item<T>* v_to_add = new Item<T>(*temp);
			v_to_add->value = val;
	
			//rearange pointers
			v_to_add->next = temp->next;
			if(v_to_add->next != NULL){v_to_add->next->prev = v_to_add; }
			temp->next = v_to_add;
					} 
	}


template <class T>
void LList<T>::remove (int position){
		if(position> this->size()-1 || position < 0)
		{throw std::out_of_range("void LList<T>::remove (int position)");}
		if(position >= 0){
			Item<T>* temp = head->next;
			for(int i=0; i<=position; i++){
				temp->prev->next = temp->next;
				if(temp->next != NULL){
					temp->next->prev = temp->prev;}
									}
		}	

}


template <class T>
void LList<T>::set (int position, const T & val){
		if(position> this->size()-1 || position < 0)
		{throw std::out_of_range("void LList<T>::set (int position, const T & val)");}
		Item<T>* temp = head;
		for(int i=0; i<=position; i++){
			temp = temp->next;}
		temp->value = val;

}


template <class T>
T& LList<T>::get (int position){
		if(position> this->size()-1 || position < 0 ||head->next==NULL)
		{throw std::out_of_range("T const& LList<T>::get (int position) const");}
		Item<T>* temp = head->next;
		for(int i=0; i<position; i++){
			temp = temp->next;}
		return temp->value; 
}


template <class T>
T const& LList<T>::get (int position) const{ 
		if(position> this->size()-1 || position < 0||head->next==NULL)
		{throw std::out_of_range("T const& LList<T>::get (int position)");}
		Item<T>* temp = head->next;
		for(int i=0; i<position; i++){
			temp = temp->next;}

		return temp->value; 
}


template <class T>
LList<T>::LList(const LList<T>&){}


//template <class T>
//LList& LList<T>::operator=(const LList<T>&){}
