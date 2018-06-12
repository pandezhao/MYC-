#include<iostream>
using namespace std;
int main(){
	int a=0,tmp=0,he=0;
	cin>>a;
	for (int i=0;i<5;++i){
		cin>>tmp;
		if (tmp<a)
			he+=tmp;	
	}
	cout<<he<<endl;
    return 0;
}
