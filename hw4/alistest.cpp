#include "AList.h"

using namespace std;

struct cmon {
	int name;
	int* followers;
	cmon(int n){name =n;}
};

int main(){
	AList<int*> test;
	int* a = new int;
	*a =5;
	int* b = new int;
	*b = 6;
	int* c = new int;
	*c = 7;
	int* d = new int;
	*d = 8;

test.insert(0,a);
test.insert(0,b);
test.insert(0,c);
test.insert(0,d);

for (int i = 0; i < 4; ++i)
{
	cout<< *test.get(i)<< endl;
}


}