#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
using namespace std;

class city{

	public:
		

}

class game{
	city *citys[];
	time timer;

	public:
		game(int a,int b,int c,int d,int e,int f, int g,int h,int i,int j,int k,int l,int m,int n,int o){

		}
		void birth(){} //
		void escape(){} //
		void march(){} //
		void fangjian(){} //
		void qingzhen(){} //
		void battle(){}  //
		void fanji(){} //
		void killed(){} //
		void huanhu(){} //
		void jiaxue(){} //
		void shengqi(){} //
		void laojia(){} //
		bool zhanlinglaojia(){} //
		void baogaoxueliang(){} //
		void baogaowuqi(){} //

		void start(){
			bool flag = true;
			while(flag){
				if (timer.shijian()==5000){
					flag = false;
				}
				if (timer.fen==0){
					birth();
				}
				if (timer.fen==5){
					escape();
				}
				if (timer.fen==10){
					march();
					laojia();
					if (zhanlinglaojia()){
						break;
					};
				}
				if (timer.fen==20){
					for (int ){}
				}
				if (timer.fen==30){
					jiaxue();
				}
				if (timer.fen==35){
					fangjian();
				}
				if (timer.fen==38){
					qingzhen();
				}
				if (timer.fen==40){
					battle();
					fanji();
					killed();
					huanhu();
					shengqi();
				}
				if (timer.fen==50){
					baogaoxueliang(){}
				}
				if (timer.fen==55){
					baogaowuqi(){}
				}
			}
		}

};

class time{
	int shi;
	public:
	int fen;
	public:
		time(){
			int shi=0;
			int fen=-5;
		}
		int shijian(){
			fen+=1;
			if (fen>=60){
				shi++;
				fen=0;
			}
			//cout<<setfill('0')<<setw(3)<<shi<<':'<<setfill('0')<<setw(2)<<fen<<' ';
			if (shi==83&&fen==20){
				return 5000;
				}
			return fen;
		}
		int zhanshi(){
			cout<<setfill('0')<<setw(3)<<shi<<':'<<setfill('0')<<setw(2)<<fen<<' ';
			return fen;
		}
};

int main(){
	int t;
	cin>>t;
	int M,N,R,K,T;
	int dragon_life,ninja_life,iceman_life,lion_life,wolf_life;
	int dragon_attach,ninja_attack,iceman_attack,lion_attack,wolf_attack;
	for (int i=0;i<t;i++){
		cin>>M>>N>>R>>K>>T;
		cin>>dragon_life>>ninja_life>>iceman_life>>lion_life>>wolf_life;
		cin>>dragon_attach>>ninja_attack>>iceman_attack>>lion_attack>>wolf_attack;
		int time=0;
	}
	return 0;
}
