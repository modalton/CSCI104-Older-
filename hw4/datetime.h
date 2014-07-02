#ifndef DATETIME_H
#define DATETIME_H
#include <iostream>

/**
 * Models a timestamp in format YYYY-MM-DD HH:MM:SS 
 */
struct DateTime
{
  /**
   * Constructor
   */
  DateTime();

  /**
   * Another constructor 
   */
  DateTime(int hh, int mm, int ss, int year, int month, int day);

  /**
   * Return true if the timestamp is less-than other's
   *
   * @return result of less-than comparison of timestamp
   */
  bool operator<(const DateTime& other);

  /**
   * Return true if the timestamp is greater-than other's
   *
   * @return result of greater-than comparison of timestamp
   */
  bool operator>(const DateTime& other);

  /**
   * Outputs the timestamp to the given ostream in format:
   *   YYYY-MM-DD HH::MM::SS
   *
   * @return the ostream passed in as an argument
   */
  friend std::ostream& operator<<(std::ostream& os, const DateTime& other);

  int h;
  int m;
  int s;
  int yr;
  int mn;
  int d;


};


#endif