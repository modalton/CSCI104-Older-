
#include <stdexcept>

//template <class T>
//Set<T>::Set(){}  //constructor
/*
template <class T>
Set<T>::Set(const Set<T> & other){} //copy constructor

template <class T>  //deconstructor
Set<T>::~Set(){}
*/
template <class T>
Set<T> Set<T>::setIntersection (const Set<T> & other) const{
	Set<T> intersect;
	Set<T> new_obj;

	typename std::set<T>::iterator it;
		 	for(it = this->begin(); it != this->end();it++ ){
			 		if(other.find(it) != other.end()){ 
			 			new_obj.add(it);
			 		}
			 }

	
	return new_obj;
}
     

template <class T>
Set<T> Set<T>::setUnion (const Set<T> & other) const{
	Set<T> new_obj;
	typename std::set<T>::iterator it;
		 	for(it = this->begin(); it != this->end();it++ ){
			 		new_obj.add(it);
			 	}


	typename std::set<T>::iterator it2;
		 	for(it2 = other.begin(); it2 != other.end();it2++ ){
			 		new_obj.add(it2);
			 	}


	return new_obj;
}

/*
template <class T> 
void Set<T>::add(const T & other){
	if(this->contains(other)){ throw std::invalid_argument("void Set<T>::add(const T & other)- already in set");}
	internalStorage.insert(0, other);
	}   //throws exception if alread in set

template <class T>
void Set<T>::remove (const T & item){
	if(this->contains(item)==false){ throw std::invalid_argument("void Set<T>::remove (const T & item)- set doesn't contain item");}

	for(int i =0; i<internalStorage.capacity;i++)
	{if(internalStorage.get(i)==item){ internalStorage.remove(i);  return;}

	}

}
      

template <class T>
bool Set<T>::contains (const T & item) const{
	for(int i =0; i<internalStorage.capacity;i++)
		{if(internalStorage.get(i)==item){ return true;}}
	return false;}
      

template <class T>
int Set<T>::size () const{return internalStorage.capacity;}
      

template <class T>
bool Set<T>::isEmpty () const{
	if(internalStorage.capacity==0){return false;}
	else{return true;}
}
     

template <class T>
T* Set<T>::first (){
	if(internalStorage.capacity==0){return NULL;}
	else{return &internalStorage.get(0);} //insert RAND
}
      

template <class T>
T* Set<T>::next (){
	first_num = last_num%internalStorage.size();
	last_num = (last_num+1)%internalStorage.size();
//std:: cout << "First num-" << first_num <<"   last num-" << last_num%internalStorage.size()<< "\n";
	return &internalStorage.get((last_num)%internalStorage.size());
}

template <class T>
T* Set<T>::commonsense(int pos){ return &internalStorage.get(pos);}

template<class T>
int Set<T>::fnum(){return last_num;}
*/

template<class T>
    void Set<T>::add (const T & item){
    	std::set<T>::insert(item);
    }
