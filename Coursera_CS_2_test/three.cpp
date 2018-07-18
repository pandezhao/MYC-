#include <iostream>
using namespace std;

int main(){
	int a,b,c;
	char trash;
	cin>>a>>trash>>b>>trash>>c;
	if (a+b==c){
		cout<<'+'<<endl;
		return 0;
	}
	if (a-b==c){
		cout<<'-'<<endl;
		return 0;
	}
	if (a*b==c){
		cout<<'*'<<endl;
		return 0;
	}
	if (a/b==c){
		cout<<'/'<<endl;
		return 0;
	}
	if (a%b==c){
		cout<<'%'<<endl;
		return 0;	
	}
	cout<<"error"<<endl;
	return 0;

}
