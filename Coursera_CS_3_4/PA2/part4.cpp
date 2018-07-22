#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class bignumber {
	public:
		string shu;
		bignumber(string tmp){
			shu = tmp;
	}
		bignumber(const bignumber& tmp){
			shu=tmp.shu;
	}
		void print(){
			cout<<shu;
	}
		bignumber& operator+(const bignumber& tmp){
			if (shu[0]=='-'&&tmp.shu[0]=='-'){

			}
			else if (shu[0]=='-'){}

			else if (tmp.shu[0]=='-'){}

			else {
				string result="";
				int jinwei=0;
				int sheiduan = min(shu.length(),tmp.shu.length()); 			
				for (int i=0;i<sheiduan;i--){
					atoi(shu[shu.length()-i].c_str()) + atoi(tmp.shu[tmp.shu.length()-i].c_str())
				}
			}
	}
};
int main(){
	string tmp1;
	string tmp2;
	char fu;
	cin>>tmp1>>fu>>tmp2;
	bignumber a(tmp1),b(tmp2);
	a.print();
	b.print();
	
}
