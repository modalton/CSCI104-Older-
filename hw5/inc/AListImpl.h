#include <iostream>
#include <stdexcept>

template <class T>
 AList<T>::AList (){head = new T[5]; _size = 5; capacity = 0;}   // constructor

template <class T>
 AList<T>::~AList (){delete [] head; }  // destructor

template <class T>
int AList<T>::size() const{
	return capacity; 

}


template <class T> 
AList<T>::AList(const AList<T>& other){
   _size = other.size();
  capacity = other.size();
   head = new T[_size];
   for(int i=0; i < _size; i++){
     head[i] = other.get(i);
   }
}


template <class T>
void AList<T>::insert (int position, const T & val){
	if(position < 0|| position > capacity){throw std::out_of_range("void AList<T>::insert (int position, const T & val)");} //check if positions is ahead of capacity!


//if it needs to make a bigger array does so here
	if(capacity+1 <= _size){
		T* temp= new T[_size]; 
// maybe later insert copy constructor
			for(int i=0; i < _size; i++)
			{ temp[i] = head[i];}

//delete and redeclare larger head
		delete[] head;
		head = new T[_size*2];
		for(int i=0; i < _size; i++)
			{head[i] = temp[i];}
		_size = _size*2;	
		delete temp;}
		
//shifting everything after
	for(int j=0; j<capacity-position;j++){
		head[capacity-j]= head[capacity-j-1];
		}

	head[position] = val; 
	capacity++;	
	
	}


template <class T>
void AList<T>::remove (int position){
	if(position < 0 || position > capacity){throw std::out_of_range("void AList<T>::remove (int position)"); }  //also for greater than list 
	else{	
		for(int i=0; i<capacity-position; i++){
			head[position+i]= head[position+i+1];}
	capacity--;
	    }	

}


template <class T>
void AList<T>::set (int position, const T & val){
		if(position < 0 || position>capacity){throw std::out_of_range("void AList<T>::set (int position, const T & val)");} //throw stuff
		head[position] = val;

}


template <class T>
T& AList<T>::get (int position){
		if(position < 0 || position>capacity){throw std::out_of_range("T& AList<T>::get (int position)");} 
		return head[position]; }


template <class T>
T const& AList<T>::get (int position) const{ 		
		if(position < 0 || position>capacity){throw std::out_of_range("T& AList<T>::get (int position)");} 
		return head[position]; 
}



template <class T>
AList<T>& AList<T>::operator=( AList<T> const& other){
		delete[] head;
		head = new T[other.size()];
		_size = other.size();
		capacity = other.size();
		for (int i = 0; i < capacity; ++i)
		{
			head[i]= other.get[i];
		}}






		

