#include <iostream>
using namespace std;
int main(){
	char data[500]={0},word[500]={0},tmp[500]={0};
	int iter=0,length=0,max=0;
	cin.getline(data,500);
	for (int i=0;i<500;++i){
		if (data[i]!=' '&&data[i]!='.'){
			tmp[iter]=data[i];
			iter++;
			length++;
		}
		else{
			if (length>max){
				max=length;
				for (int j=0;j<500;++j){
					word[j]=tmp[j];
					tmp[j]=0;
				}
				max = length;
				length = 0;	
				iter=0;	
			}
			else {
				for (int j=0;j<500;++j)
					tmp[j]=0;
				iter=0;
				length=0;
			}
			if (data[i]=='.')
				break;
		}
	}
	cout<<word<<endl;
    return 0;
}
