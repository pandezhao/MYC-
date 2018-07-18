#include <iostream>
using namespace std;

int main(){
	int m,k;
	cin>>m>>k;
	int counter = 0,tmp=m;
	for (int i=0;i<6;i++){
		if (tmp%10==3){
			counter++;
		}
		tmp/=10;
	}
	if (m%19==0 && counter==k)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
