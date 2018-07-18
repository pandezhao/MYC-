#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int zu[n][2];
	for (int i=0;i<n;i++){
		cin>>zu[i][0]>>zu[i][1];
	}
	int counter = 0;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (j!=i){
				if (zu[j][0]>=zu[i][0]&&zu[j][1]>=zu[i][1])
					break;
				else if (j==n-1||(i==n-1&&j==n-2))
					counter++;
			}
		}		
	}
	int cishu=0;
	for (int i=1;i<n;i++){
		for (int j=0;j<n-i;j++){
			if (zu[j][0]>zu[j+1][0]){
				int a=zu[j+1][0];
				int b=zu[j+1][1];
				zu[j+1][0]=zu[j][0];
				zu[j+1][1]=zu[j][1];
				zu[j][0]=a;
				zu[j][1]=b;
			}
		}	
	}

	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (j!=i){
				if (zu[j][0]>=zu[i][0]&&zu[j][1]>=zu[i][1])
					break;
				else if (j==n-1||(i==n-1&&j==n-2)){
					cout<<'('<<zu[i][0]<<','<<zu[i][1]<<')';
					cishu++;
					if (cishu<counter)
						cout<<',';
				}
			}
		}
	}
	cout<<endl;
	return 0;
}
