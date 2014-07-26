 
  #include "datetime.h"
  #include <sstream>
  DateTime::DateTime(){
  h= 0;
  m = 0;
  s=0;
  yr=0;
  mn= 0;
  d=0;

  }

  DateTime::DateTime(int hh, int mm, int ss, int year, int month, int day){
 	h= hh;
	m = mm;
	s=ss;
	yr=year;
 	mn= month;
 	d=day;


	  }

  std::string DateTime::DateTime_string(){
    std::ostringstream convert;
    std::string Result;          // string which will contain the result

    convert << yr << "-" << mn << "-" << d << " "<< h<< ":" << m << ":" <<s;     
    Result = convert.str();
  /*  convert << mn;     
    Result += convert.str();
    convert << d;     
    Result += convert.str();
    convert << h;     
    Result += convert.str();
    convert << m;     
    Result += convert.str();
    convert << s;     
    Result += convert.str(); */

    return Result;
  }

//less than
 bool DateTime::operator<(const DateTime& other) const{
 	if(yr<other.yr){return true;}
  if(yr>other.yr){return false;}
  if(mn<other.mn){return true;}
  if(mn>other.mn){return false;}
  if(d<other.d){return true;}
  if(d>other.d){return false;}
 	if(h<other.h){return true;}
  if(h>other.h){return false;}
 	if(m<other.m){return true;} 
  if(m>other.m){return false;} 
  if(s<other.s){return true;}
  if(s>other.s){return false;}
  if(s==other.s && d==other.d &&m==other.m && h==other.h && mn==other.mn && yr==other.yr){return false;}
    return false;}

 bool DateTime::operator>(const DateTime& other) const{
 	  if(*this<other){return false;}
  if(s==other.s && d==other.d &&m==other.m && h==other.h && mn==other.mn && yr==other.yr){return false;}
    return true;}
 


std::ostream& operator<<(std::ostream& os, const DateTime& other){
  os<< other.yr << "-";
  if(other.mn<10){os<<"0";}
  os << other.mn<< "-";
  if(other.d<10){os<<"0";}
  os << other.d<< " ";
  if(other.h<10){os<<"0";}
  os << other.h<< ":";
  if(other.m<10){os<<"0";}
  os << other.m << ":";
  if(other.s<10){os<<"0";}
  os << other.s ;

  return os;
 }