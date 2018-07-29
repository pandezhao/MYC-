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
		bignumber():shu(""){}

		bignumber operator=(const bignumber& tmp){
			shu = tmp.shu;
			}

		bignumber operator+(const bignumber& tmp){
			if (shu[0]=='-' && tmp.shu[0]=='-'){
				string a = shu.substr(1,shu.length()-1);
				string b = tmp.shu.substr(1, tmp.shu.length()-1);
				bignumber jiashu1(a),jiashu2(b);
				bignumber result = jiashu1 + jiashu2;
				result.shu = '-' + result.shu;
				return result;
			}
			else if (shu[0]=='-'){
				string a = shu.substr(1,shu.length()-1);
				bignumber jiashu1(shu), jiashu2(a);
				bignumber result = jiashu1 - jiashu2;
				return result;
			}
			else if (tmp.shu[0]=='-'){
				string a = tmp.shu.substr(1,tmp.shu.length()-1);
				bignumber jiashu1(shu), jiashu2(a);
				bignumber result = jiashu1 - jiashu2;
				return result;
			}
			else{
				int duan = min(shu.length(), tmp.shu.length());
				int jinwei = 0;
				string result = "";
				for (int i=1;i<=duan;i++){
					int jiashu1 = (int)shu[shu.length()-i]-48;
					int jiashu2 = (int)tmp.shu[tmp.shu.length()-i]-48;
					int result_tmp = jiashu1 + jiashu2 + jinwei;
					if (result_tmp>=10){
						result_tmp -= 10;
						jinwei = 1; 
					}
					else {
						jinwei = 0;
					}
					char zixing_tmp = (char)(result_tmp + 48);
					result = zixing_tmp + result;
				}
			}
		}

		bignumber operator-(const bignumber& tmp){
			if (shu[0]=='-' && tmp.shu[0]=='-'){
				string a = shu.substr(1,shu.length()-1);
				string b = tmp.shu.substr(1, tmp.shu.length()-1);
				bignumber jiashu1(a), jiashu2(b);
				bignumber result = jiashu2 - jiashu1;
				return result;
			}
			else if (shu[0]=='-'){
				string a = shu.substr(1,shu.length()-1);
				string b = tmp.shu;
				bignumber jiashu1(a), jiashu2(b);
				bignumber result = jiashu1 + jiashu2;
				result.shu = '-' + result.shu;
				return result;
			}
			else if (tmp.shu[0]=='-'){
				string a = shu;
				string b = tmp.shu.substr(1, tmp.shu.length()-1);
				bignumber jiashu1(a), jiashu2(b);
				bignumber result = jiashu1 + jiashu2;
				return result;
			}
			else {

			}
		}
};
int main(){
	string tmp1;
	string tmp2;
	char fu;
	cin>>tmp1>>tmp2;
	bignumber a(tmp1);
	bignumber b(tmp2);
	cout<<a.shu<<endl;
	cout<<b.shu<<endl;
	cout<<(a+b).shu<<endl;;
	
	
}






















