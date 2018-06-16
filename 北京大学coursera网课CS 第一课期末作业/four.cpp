#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int x=0,y=0,result=0;
	char operat=' ';
	cin>>x>>y>>operat;
	switch (operat){
		case '+':
			cout<<x+y<<endl;
			break;
		case '-':
			cout<<x-y<<endl;
			break;
		case '*':
			cout<<x*y<<endl;
			break;
		case '/':
			if (y==0)
				cout<<"Divided by zero"<<endl;
			else
				cout<<x/y<<endl;
			break;
		default:
			cout<<"Invalid operator!"<<endl;
			break;
	}
	return 0;
}
