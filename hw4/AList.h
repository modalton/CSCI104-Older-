#ifndef ALIST_h
#define ALIST_h 
// necessary includes can go here

/*template <class T>
struct Item
{
  T value;
  Item<T> *prev, *next;
  Item<T>();
  Item<T>( Item<T> &p );
};*/



template <class T>
class AList
{
  public:
    AList ();   // constructor

    ~AList ();  // destructor

    int size () const;  // returns the number of elements in the list

    void insert (int position, const T & val);
      /* Inserts val into the list before the given position,
         shifting all later items one position to the right.
         Inserting before 0 (i.e., position = 0) makes it the 
         new first element.
         Inserting before size() (i.e., position = size()) makes 
         it the new last element.
         Your function should throw an exception if position is
         outside the legal range, which would be 0-size() here. */

    void remove (int position);
      /* Removes the item from the given position, shifting all
         later items one position to the left.
         Your function should throw an exception if position is
         outside the legal range. */

    void set (int position, const T & val);
      /* Overwrites the given position with the given value.
         Does not affect any other positions.  
         Your function should throw an exception if position is
         outside the legal range. */

    T& get (int position) ;
      /* Returns a non-const reference to the item at the given position.
         Your function should throw an exception if position is
         outside the legal range. */

     T const& get (int position) const;
      /* Returns a const reference to the item at the given position.
         Your function should throw an exception if position is
         outside the legal range. */


      /* Head pointer to the 1st item in your linked list */

      int _size;  //needs _ or else its a duplicate of size function
      int capacity;  


    private:   
   
      T *head;
      AList(const AList& other);
      /* This is a copy constructor and we likely haven't learned how to make
         deep copies of a list yet.  Thus by making it's prototype private, the
         compiler will enforce that no one ever be allowed to make a copy of a AList */

      AList& operator=(const AList&);
      /* This is a copy constructor and we likely haven't learned how to make
         deep copies of a list yet.  Thus by making it's prototype private, the
         compiler will enforce that no one ever be allowed to make a copy of a AList */

     
    //  Item<T> *tail; WHY IS THIS CAUSING SEG FAULT?

      /* You may add further private data fields or helper methods if 
         you choose. You should not alter the public signature. */
};
#include "AList.cpp"

#endif
