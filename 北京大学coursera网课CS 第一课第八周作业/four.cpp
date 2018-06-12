# include <iostream>
using namespace std;

int main() {
    int n=0,k=0,tmp=0;
	cin>>n>>k;
	int zu[n];
	for (int i=0;i<n;++i)
		cin>>zu[i];
	for (int i=0;i<n;++i){
		tmp=k-zu[i];
		for (int j=i;j<n;++j){
			if (zu[j]==tmp){
				cout<<"yes"<<endl;
				return 0;
			}
		}
	}
	cout<<"no"<<endl;
    return 0;
}
