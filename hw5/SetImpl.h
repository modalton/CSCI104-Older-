
#include <stdexcept>

template <class T>
Set<T>::Set(){}  //constructor

template <class T>
Set<T>::Set(const Set<T> & other){} //copy constructor

template <class T>  //deconstructor
Set<T>::~Set(){}
/*
template <class T>
Set<T> Set<T>::setIntersection (const Set<T> & other) const{
	Set<T> intersect;
	Set<T> new_obj;
	for (int i = 0; i < internalStorage.size(); i++)
	
	{if(other.contains(internalStorage.get(i))){ new_obj.add(internalStorage.get(i)); std::cout<<"intersect "<<internalStorage.get(i)<<"\n"; }}

	return new_obj;
}
     

template <class T>
Set<T> Set<T>::setUnion (const Set<T> & other) const{
	Set<T> new_obj;
	for (int i = 0; i < internalStorage.size(); i++)
	{ new_obj.add(internalStorage.get(i));std::cout<< internalStorage.get(i)<< "\n";}

	for (int i=0; i < other.size(); i++)
		{if(new_obj.contains(other.internalStorage.get(i))){}
		else{new_obj.add(other.internalStorage.get(i)); std::cout<< other.internalStorage.get(i)<< "\n";}
				}

	return new_obj;
}


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
