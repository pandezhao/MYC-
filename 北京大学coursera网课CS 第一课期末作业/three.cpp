#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
	int n=0;
	cin>>n;
	double x[n]={0},y[n]={0};
	int num = n*(n+1)/2,count=0;
	double dis[num]={0};
	for (int i=0;i<n;++i){
		cin>>x[i]>>y[i];
	}
	for (int i=0;i<n;++i){
		for (int j=i+1;j<n;++j){
			dis[count]= sqrt((x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i] - y[j]));
			count++;
		}
	}
	double max = 0;
	for (int i=0;i<num;i++){
		if (dis[i]>max){
			max = dis[i];
		}
	}
	cout<<fixed<<setprecision(4)<<max<<endl;
    return 0;
}
