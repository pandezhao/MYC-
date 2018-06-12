#include <iostream>
using namespace std;
int main(){
	double N=0,K=0,price = 200;
	cin>>N>>K;
	for (int i=1;;++i){
		if (N*i>=price){
			cout<<i<<endl;
			break;	
			}
		if (price*K/100>N){
			cout<<"Impossible"<<endl;
			break;
			}
		price+=(price*K/100);
	}
    return 0;
}
