#include <iostream>
using namespace std;

int main(){
	int L,M;
	cin>>L>>M;
	int zu[L+1];
	for (int i=0;i<L+1;i++)
		zu[i]=1;
	for (int i=0;i<M;i++){
		int a=0,b=0;
		cin>>a>>b;
		for (int j=a;j<b+1;j++){
			zu[j]=0;
		}
	}
	int he=0;
	for (int i=0;i<L+1;i++)
		he+=zu[i];
	cout<<he<<endl;
	return 0;
}
