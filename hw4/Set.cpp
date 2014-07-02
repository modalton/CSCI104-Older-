#include <stdexcept>

template <class T>
Set<T>::Set(){}  //constructor

template <class T>
Set<T>::Set(const Set<T> & other){} //copy constructor

template <class T>  //deconstructor
Set<T>::~Set(){}

template <class T> 
void Set<T>::add(const T & other){
	if(this->contains(other)){ throw;}
	internalStorage.insert(0, other);
	}   //throw exception if alread in set

template <class T>
void Set<T>::remove (const T & item){
	if(this->contains(item)==false){throw;}

	for(int i =0; i<internalStorage.capacity;i++)
	{if(internalStorage.get(i)==item){ internalStorage.remove(i);  return;}

	}

}
      /* Removes the item from the set.
         Throws an exception if the set does not contain the item. */

template <class T>
bool Set<T>::contains (const T & item) const{
	for(int i =0; i<internalStorage.capacity;i++)
		{if(internalStorage.get(i)==item){ return true;}}
	return false;}
      /* Returns true if the set contains the item, and false otherwise. */

template <class T>
int Set<T>::size () const{return internalStorage.capacity;}
      /* Returns the number of elements in the set. */

template <class T>
bool Set<T>::isEmpty () const{
	if(internalStorage.capacity==0){return false;}
	else{return true;}
}
      /* Returns true if the set is empty, and false otherwise. */

template <class T>
Set<T> Set<T>::setIntersection (const Set<T> & other) const{
	Set<T> intersect;
	Set<T> new_obj;
	for (int i = 0; i < internalStorage.size(); i++)
	
	{if(other.contains(internalStorage.get(i))){ new_obj.add(internalStorage.get(i)); std::cout<<"intersect "<<internalStorage.get(i)<<"\n"; }}

	return new_obj;
}
      /* Returns the intersection of the current set with other.
         That is, returns the set of all items that are both in this
         and in other. */

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
      /* Returns the union of the current set with other.
         That is, returns the set of all items that are in this set
         or in other (or both).
         The resulting set should not contain duplicates. */

    /* The next two functions together implement a suboptimal version
       of what is called an "iterator".
       Together, they should give you a way to loop through all elements
       of the set. The function "first" starts the loop, and the function
       "next" moves on to the next element.
       You will want to keep the state of the loop inside a private variable.
       We will learn the correct way to implement iterators soon, at 
       which point you will replace this.
       For now, we want to keep it simple. */

template <class T>
T* Set<T>::first (){
	if(internalStorage.capacity==0){return NULL;}
	else{return &internalStorage.get(0);} //insert RAND
}
      /* Returns the pointer to some element of the set, 
         which you may consider the "first" element.
         Should return NULL if the set is empty. */

template <class T>
T* Set<T>::next (){
	first_num = last_num%internalStorage.size();
	last_num = (last_num+1)%internalStorage.size();
//std:: cout << "First num-" << first_num <<"   last num-" << last_num%internalStorage.size()<< "\n";
	return &internalStorage.get((last_num)%internalStorage.size());
}
      /* Returns the pointer to an element of the set different from all 
         the ones that "first" and "next" have returned so far. 
         Should return NULL if there are no more element. */

template <class T>
T* Set<T>::commonsense(int pos){ return &internalStorage.get(pos);}

template<class T>
int Set<T>::fnum(){return last_num;}

