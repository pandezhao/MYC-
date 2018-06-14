#include <iostream>
using namespace std;
    
int main() {
	char s1[80]={0},s2[80]={0};
	cin.getline(s1,80);
	cin.getline(s2,80);
	int a,b;
	for (int i=0;i<80;++i){
		a = (int)s1[i];
		b = (int)s2[i];
		if (a>=65&&a<=90)
			a+=32;
		if (b>=65&&b<=90)
			b+=32;
		if (a>b){
			cout<<">"<<endl;
			return 0;		
		}
		if (a<b){
			cout<<"<"<<endl;
			return 0;
		}
	}
	cout<<'='<<endl;
	return 0;
}
