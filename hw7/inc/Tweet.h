#ifndef TWEET_H
#define TWEET_H
#include <iostream>
#include <map>
#include <set>
#include <string>
#include "datetime.h"
#include "User.h"
#include "AList.h"
#include "q_user.h"



/* Forward declaration */
class User;
class q_user;

/**
 * Models a tweet and provide comparison and output operators
 */
class Tweet
{
 public:
  /**
   * Default constructor 
   */
  Tweet();

 

  Tweet(const Tweet& other);
  

  Tweet(User* user, DateTime& timer, std::string& text);

//constructor that can access q_user feeds
  Tweet(User* user, DateTime& timer, std::string& text, std::map<std::string, q_user*>& master_list, bool realtime);
  

  /**
   * Gets the timestamp of this tweet
   *
   * @return timestamp of the tweet
   */
  DateTime const & time() const;

  /**
   * Gets the actual text of this tweet
   *
   * @return text of the tweet
   */
  std::string const & text() const;

  /**
   * Return true if this Tweet's timestamp is less-than other's
   *
   * @return result of less-than comparison of tweet's timestamp
   */
  bool operator<(const Tweet& other) const{
    return _time < other._time;
  }

  /**
   * Return true if this Tweet's timestamp is greater-than other's
   *
   * @return result of greater-than comparison of tweet's timestamp
   */
  bool operator>(const Tweet& other) const{
    return _time > other._time;
  }

  /**
   * Outputs the tweet to the given ostream in format:
   *   YYYY-MM-DD HH::MM::SS username tweet_text
   *
   * @return the ostream passed in as an argument
   */
  friend std::ostream& operator<<(std::ostream& os, const Tweet& t);
  

  /* Create any other public or private helper functions you deem 
     necessary */

  std::string FullTweet();

  void spliceHashtags();

  std::set<std::string> getHashTags();


 private:
  std::set<std::string> _hashtags;
  DateTime _time;
  std::string _text;
  User* _poster;

  /* Add any other data members you need here */


};

/* Leave this alone */
struct TweetComp
{
  bool operator()(Tweet* t1, Tweet* t2)
  {
    return (*t1 > *t2);
  }
};
#endif