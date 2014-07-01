 
  DateTime::DateTime(int hh, int mm, int ss, int year, int month, int day){
 	h= hh;
	m = mm;
	s=ss;
	yr=year;
 	mn= month;
 	d=day;
	  }


 bool DateTime::operator<(const DateTime& other){
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
 	if(this<other ==false){return true;}
 }