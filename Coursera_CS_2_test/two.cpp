#include <iostream>
using namespace std;
class character{
	public:
	int word;
	int time=0;
	character *next=NULL;

	character(int a,int b){
	word = a;
	time = b;
}
};

bool zifu(char tmp){
	if (((int)tmp>64&&(int)tmp<91)||((int)tmp>96&&(int)tmp<123)){
		cout<<tmp<<' '<<"True"<<endl;
		return true;}
	else{
		cout<<"false"<<endl;
		return false;
}
}

int fanyi(char tmp){
	if ((int)tmp<91)
		return (int)tmp-65;
	else 
		return (int)tmp-97;
}

int main(){
	char ku[501]={'\0'};
	cin.getline(ku, 501);
	character head(-1,0);
	character *tmp = &head;
	cout<<"all data get"<<endl;
	for (int i=0;i<501;i++){
		cout<<i<<endl;
		if (zifu(ku[i])){
			while((tmp->next!=NULL)&&(tmp->word!=fanyi(ku[i]))){
				tmp=tmp->next;
			}
			if (tmp->next==NULL){
				character xin(fanyi(ku[i]), 1);
				tmp->next = &xin;
				tmp=&head;
				cout<<"er"<<endl;
			}
			else if (tmp->word==fanyi(ku[i])){
				tmp->time+=1;
				tmp=&head;
				cout<<"san"<<endl;
			}
		}
	}
	cout<<"chain built"<<endl;
	int max=0;
	while(tmp->next!=NULL){
		if (tmp->time>max){
			max=tmp->time;
			tmp=tmp->next;
		}
	}
	tmp=&head;
	int xiaomax=0;
	cout<<"max get"<<endl;
	while(tmp->next!=NULL){
		if (tmp->time>xiaomax&&tmp->time!=max){
			xiaomax=tmp->time;
			tmp=tmp->next;
		}
	}
	cout<<"second max get"<<endl;
	tmp=&head;
	while(tmp->time!=xiaomax){
		tmp=tmp->next;
	}
	char a=(char)tmp->word+65;
	char b=(char)tmp->word+97;
	cout<<a<<'+'<<b<<':'<<tmp->time<<endl;


	return 0;
}















