#ifndef SET_h
#define SET_h 
#include "AList.h"
#include <set>


template <class T>
class Set : public std::set<T>{
  public: 
  //  Set (): std::set<T>(){}                     // constructor for an empty set
  //  Set (const Set<T> & other); // copy constructor, making a deep copy
  //  ~Set ();                    // destructor

      void add (const T & item);

    Set<T> setIntersection (const Set<T> & other) const;
      /* Returns the intersection of the current set with other.
         That is, returns the set of all items that are both in this
         and in other. */

    Set<T> setUnion (const Set<T> & other) const;
      /* Returns the union of the current set with other.
         That is, returns the set of all items that are in this set
         or in other (or both).
         The resulting set should not contain duplicates. */

/*
 
      

    void remove (const T & item);
      

    bool contains (const T & item) const;
     

    int size () const;
    

    bool isEmpty () const;
     


    

    T* first ();
      
    T* next ();
      

    T* commonsense(int pos);

    int fnum();

  private:
    AList <T> internalStorage;
    int first_num;
    int last_num;  
    */

    // other private variables you think you need.

};
#include "SetImpl.h"

#endif