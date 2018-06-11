#include <iostream>
#include <iomanip>
using namespace std;

int main(){

double n=0,one=0,two=0,three=0,four=0,tmp=0;
double output=0;

cin>>n;
for (int i=0;i<n;++i){
	cin>>tmp;
	if (tmp>1&&tmp<=18)
		++one;
	else if (tmp>=19&&tmp<=35)
		++two;
	else if (tmp>=36&&tmp<=60)
		++three;
	else if (tmp>60)
		++four;
	}
output = one / n * 100;
cout<<"1-18: "<<fixed<<setprecision(2)<<output<<'%'<<endl;
output = two / n * 100;
cout<<"19-35: "<<output<<'%'<<endl;
output = three / n * 100;
cout<<"36-60: "<<output<<'%'<<endl;
output = four / n * 100;
cout<<"60-: "<<output<<'%'<<endl;

return 0;
}
