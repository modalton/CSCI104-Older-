#ifndef SET_h
#define SET_h 
#include "AList.h"

template <class T>
class Set {
  public: 
    Set ();                     // constructor for an empty set
    Set (const Set<T> & other); // copy constructor, making a deep copy
    ~Set ();                    // destructor

    void add (const T & item); 
      /* Adds the item to the set. 
         Throws an exception if the set already contains the item. */

    void remove (const T & item);
      /* Removes the item from the set.
         Throws an exception if the set does not contain the item. */

    bool contains (const T & item) const;
      /* Returns true if the set contains the item, and false otherwise. */

    int size () const;
      /* Returns the number of elements in the set. */

    bool isEmpty () const;
      /* Returns true if the set is empty, and false otherwise. */

    Set<T> setIntersection (const Set<T> & other) const;
      /* Returns the intersection of the current set with other.
         That is, returns the set of all items that are both in this
         and in other. */

    Set<T> setUnion (const Set<T> & other) const;
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

    T* first ();
      /* Returns the pointer to some element of the set, 
         which you may consider the "first" element.
         Should return NULL if the set is empty. */

    T* next ();
      /* Returns the pointer to an element of the set different from all 
         the ones that "first" and "next" have returned so far. 
         Should return NULL if there are no more element. */

  private:
    AList <T> internalStorage;
    int first_num;
    int last_num;
    // other private variables you think you need.
};

#include "Set.cpp"
#endif