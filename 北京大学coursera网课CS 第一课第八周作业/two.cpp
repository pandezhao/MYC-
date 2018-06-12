#include <iostream>
using namespace std;
    
int main() {
	int n=0;
	cin>>n;
	double tmp[n];
	for (int i=0;i<n;++i)
		cin>>tmp[i];
	for (int i=0;i<n;++i){
		if (tmp[i]/3.0+50>tmp[i]/1.2)
			cout<<"Walk"<<endl;
		else if (tmp[i]/3.0+50<tmp[i]/1.2)
			cout<<"Bike"<<endl;
		else
			cout<<"All"<<endl;
	}
	return 0;
}
