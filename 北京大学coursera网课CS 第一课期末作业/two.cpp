#include <iostream>
using namespace std;
int main() {
	int i=0;
	while(cin>>i){
	int flag = 0;
	if (i % 3 == 0){
		cout<<3<<' ';
		flag = 1;	
	}
	if (i % 5 == 0){
		cout<<5<<' ';
		flag = 1;
	}
	if (i % 7 == 0){
		cout<<7<<endl;
		flag = 1;
	}
	else if (flag==1)
		cout<<endl;
	if (flag==0)
		cout<<'n'<<endl;}
	return 0;
}
