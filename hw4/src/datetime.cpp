 
  #include "datetime.h"
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


 bool DateTime::operator<(const DateTime& other){
  std::cout<<"my secs" << s << " other secs:" << other.s <<"\n";
 	if(yr>other.yr){return false;}
  if(mn>other.mn){return false;}
  if(d>other.d){return false;}
 	if(h>other.h){return false;}
 	if(m>other.m){return false;} 
  if(s>other.s){return false;}
  if(s==other.s && d==other.d &&m==other.m && h==other.h && mn==other.mn && yr==other.yr){return false;}
  	return true;}

 bool DateTime::operator>(const DateTime& other){
 	if(s==other.s && d==other.d &&m==other.m && h==other.h && mn==other.mn && yr==other.yr){return false;}
 	if(*this<other ==false){return true;}
  return false;
 }


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
  os << other.m ;

  return os;
 }