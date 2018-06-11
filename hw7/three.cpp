#include <iostream>

using namespace std;

int main(){
int N=0,K=0,tmp=0;
cin>>N>>K;
int rec = K;
int zu[N];
for (int i=0;i<N;i++){
	cin>>zu[i];
	}
for (int i=0;i<N;++i){
	while (K){
		for (int k=0;k<N;++k)
			cout<<zu[k]<<" ";
		cout<<endl;
		for (int j=0;j<N-i;++j){
			if (zu[j]>zu[j+1]){
				tmp = zu[j+1];
				zu[j+1] = zu[j];
				zu[j] = tmp;			
				}
			}	
	K--;}
	}
cout<<zu[N-rec]<<endl;
return 0;
}
