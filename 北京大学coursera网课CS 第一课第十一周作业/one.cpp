#include<iostream>
using namespace std;
int main(){
	char s[80];
	int result[600]={0};
	cin.getline(s,80);
	for (int i=0;i<80;++i){
		result[(int)s[i]]++;
	}
	cout<<result[97]<<" "<<result[101]<<" "<<result[105]<<" "<<result[111]<<" "<<result[117]<<endl;
    return 0;
}
