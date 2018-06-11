#include <iostream>

using namespace std;

int main(){
int bai=0,wushi=0,ershi=0,shi=0,wu=0,yi=0;
int qian=0;
cin>>qian;

bai = qian / 100;
qian = qian % 100;

wushi = qian /50;
qian = qian % 50;

ershi = qian / 20;
qian = qian % 20;

shi = qian / 10;
qian = qian % 10;

wu = qian / 5;
qian = qian % 5;

yi = qian / 1;

cout<<bai<<"\n"<<wushi<<"\n"<<ershi<<"\n"<<shi<<"\n"<<wu<<"\n"<<yi<<endl;


return 0;
}
