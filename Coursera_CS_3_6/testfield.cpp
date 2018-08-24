#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
using namespace std;
class test{
	int tmp;
	public:
		test(int i){tmp = i;}
		void print(){
			cout<<"ceshi "<<tmp<<endl;
		}	

};

test* test_test(){
	test* i = new test(4);
	return i;
}

void test_zhengshu(int test){
	if(test==NULL){
		cout<<"de dao kong zhi"<<endl;
	}else{
	cout<<test<<endl;}
}

int main(){
	int i=3;
	test* a=NULL;
	delete a;
	return 0;
}
