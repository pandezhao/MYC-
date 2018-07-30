#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
using namespace std;

class weapon{
public:
	string name;
	weapon(int bianhao){
		if (bianhao==0){name="sword";		
		}
		else if(bianhao==1){name="bomb";
		}
		else if(bianhao==2){name="arrow";
		}
	}
};

class warrior{
int index;
int HP;
public:
	warrior(int a,int b){
		index = a;
		HP = b;
	}
};

class iceman:public warrior{
weapon one;
public:
	iceman(int a,int b):warrior(a,b),one(b%3){
		cout<<"It has a "<<one.name<<endl;	
	}
};

class lion:public warrior{
int loyalty;
public:
	lion(int a,int b,int c):warrior(a,b),loyalty(c){
		cout<<"It's loyalty is "<<loyalty<<endl;
	}
};

class wolf:public warrior{
public:
	wolf(int a,int b):warrior(a,b){}
};

class ninja:public warrior{
weapon one,two;
public:
	ninja(int a,int b):warrior(a,b),one(b%3),two((b+1)%3){
		cout<<"It has a "<<one.name<<" and a "<<two.name<<endl;
	}
};

class dragon:public warrior{
weapon one;
float morale;
public:
	dragon(int a,int b,float c):warrior(a,b),one(b%3),morale(c){
		cout<<"It has a "<<one.name<<",and it's morale is "<<fixed<<setprecision(2)<<morale<<endl;
	}
};


//城堡的综合类
class quarter{
private:
	int life;
	int dragon_life;
	int ninja_life;
	int iceman_life;
	int lion_life;
	int wolf_life;
	int index = 0;
	int dragons = 0;
	int ninjas = 0;
	int icemans = 0;
	int lions = 0;
	int wolfs = 0;

public:
	quarter(int a,int b,int c,int d,int e,int f):life(a),dragon_life(b),ninja_life(c),iceman_life(d),lion_life(e),wolf_life(f){}

	bool zhizao_dragon(string color,int time){
		if (life>=dragon_life){
			cout<<setfill('0')<<setw(3)<<time;
			index++;
			dragons++;
			life = life - dragon_life;
			float mor = (float)life / (float)dragon_life;
			cout<<' '<<color<<" dragon "<<index<<" born with strength "<<dragon_life<<','<<dragons<<" dragon in "<<color<<" headquarter"<<endl;
			dragon tmp(dragon_life, index, mor);
			return true;
		}else{
			return false;
		}
	}
	bool zhizao_ninja(string color,int time){
		if (life>=ninja_life){
			cout<<setfill('0')<<setw(3)<<time;
			index++;
			ninjas++;
			life = life - ninja_life;
			cout<<' '<<color<<" ninja "<<index<<" born with strength "<<ninja_life<<','<<ninjas<<" ninja in "<<color<<" headquarter"<<endl;
			ninja tmp(ninja_life, index);
			return true;
		}else{
			return false;
		}
	}
	bool zhizao_iceman(string color,int time){
		if (life>=iceman_life){
			cout<<setfill('0')<<setw(3)<<time;
			index++;
			icemans++;
			life = life - iceman_life;
			cout<<' '<<color<<" iceman "<<index<<" born with strength "<<iceman_life<<','<<icemans<<" iceman in "<<color<<" headquarter"<<endl;
			iceman tmp(iceman_life, index);
			return true;
		}else{
			return false;
		}
	}
	bool zhizao_lion(string color,int time){
		if (life>=lion_life){
			cout<<setfill('0')<<setw(3)<<time;
			index++;
			lions++;
			life = life - lion_life;
			cout<<' '<<color<<" lion "<<index<<" born with strength "<<lion_life<<','<<lions<<" lion in "<<color<<" headquarter"<<endl;
			lion tmp(lion_life, index, life);
			return true;
		}else{
			return false;
		}
	}
	bool zhizao_wolf(string color,int time){
		if (life>=wolf_life){
			cout<<setfill('0')<<setw(3)<<time;
			index++;
			wolfs++;
			life = life - wolf_life;
			cout<<' '<<color<<" wolf "<<index<<" born with strength "<<wolf_life<<','<<wolfs<<" wolf in "<<color<<" headquarter"<<endl;
			wolf tmp(wolf_life, index);
			return true;
		}else{
			return false;
		}
	}
	bool hainengxu(){
		if (life>=dragon_life||life>=iceman_life||life>=ninja_life||life>=lion_life||life>=wolf_life){
			return true;		
		}
		else{
			return false;	
		}
	}
};

//蓝色城堡
class bluequarter:public quarter{
string color = "blue";
int flag = 2; 
public:
	bluequarter(int a,int b,int c,int d,int e,int f):quarter(a,b,c,d,e,f){}

	void shengchan(int time){
		switch(flag){
		case 1:
			if (zhizao_wolf(color,time)){
				flag = 2;
				break;}
			else if(hainengxu()){
				flag = 2;
				shengchan(time);
				break;
			}
			else{
				flag = -1;
				cout<<setfill('0')<<setw(3)<<time<<" blue headquarter stops making warriors"<<endl;
				break;		
			}
		case 2:
			if (zhizao_lion(color,time)){
				flag = 5;
				break;}
			else if(hainengxu()){
				flag = 5;
				shengchan(time);
				break;
			}
			else{
				flag = -1;
				cout<<setfill('0')<<setw(3)<<time<<" blue headquarter stops making warriors"<<endl;
				break;		
			}
		case 3:
			if (zhizao_iceman(color,time)){
				flag = 1;
				break;}
			else if(hainengxu()){
				flag = 1;
				shengchan(time);
				break;
			}
			else{
				flag = -1;
				cout<<setfill('0')<<setw(3)<<time<<" blue headquarter stops making warriors"<<endl;
				break;		
			}
		case 4:
			if (zhizao_ninja(color,time)){
				flag = 3;
				break;}
			else if(hainengxu()){
				flag = 3;
				shengchan(time);
				break;
			}
			else{
				flag = -1;
				cout<<setfill('0')<<setw(3)<<time<<" blue headquarter stops making warriors"<<endl;
				break;		
			}
		case 5:
			if (zhizao_dragon(color,time)){
				flag = 4;
				break;}
			else if(hainengxu()){
				flag = 4;
				shengchan(time);
				break;
			}
			else{
				flag = -1;
				cout<<setfill('0')<<setw(3)<<time<<" blue headquarter stops making warriors"<<endl;
				break;		
			}
		case -1:
			break;
		}	
	}



};

//红色城堡
class redquarter:public quarter{
string color = "red";
int flag = 3;
public:
	redquarter(int a,int b,int c,int d,int e,int f):quarter(a,b,c,d,e,f){}

	void shengchan(int time){
		switch(flag){
		case 1:
			if (zhizao_wolf(color,time)){
				flag = 4;
				break;}
			else if(hainengxu()){
				flag = 4;
				shengchan(time);
				break;
			}
			else{
				flag = -1;
				cout<<setfill('0')<<setw(3)<<time<<" red headquarter stops making warriors"<<endl;
				break;		
			}
		case 2:
			if (zhizao_lion(color,time)){
				flag = 1;
				break;}
			else if(hainengxu()){
				flag = 1;
				shengchan(time);
				break;
			}
			else{
				flag = -1;
				cout<<setfill('0')<<setw(3)<<time<<" red headquarter stops making warriors"<<endl;
				break;		
			}
		case 3:
			if (zhizao_iceman(color,time)){
				flag = 2;
				break;}
			else if(hainengxu()){
				flag = 2;
				shengchan(time);
				break;
			}
			else{
				flag = -1;
				cout<<setfill('0')<<setw(3)<<time<<" red headquarter stops making warriors"<<endl;
				break;		
			}
		case 4:
			if (zhizao_ninja(color,time)){
				flag = 5;
				break;}
			else if(hainengxu()){
				flag = 5;
				shengchan(time);
				break;
			}
			else{
				flag = -1;
				cout<<setfill('0')<<setw(3)<<time<<" red headquarter stops making warriors"<<endl;
				break;		
			}
		case 5:
			if (zhizao_dragon(color,time)){
				flag = 3;
				break;}
			else if(hainengxu()){
				flag = 3;
				shengchan(time);
				break;
			}
			else{
				flag = -1;
				cout<<setfill('0')<<setw(3)<<time<<" red headquarter stops making warriors"<<endl;
				break;		
			}
		case -1:
			break;
		}	
	}
};

int main(){
	int times;
	cin>>times;
	for (int i=0;i<times;i++){
		int life,a,b,c,d,e;
		cin>>life>>a>>b>>c>>d>>e;
		redquarter red(life,a,b,c,d,e);
		bluequarter blue(life,a,b,c,d,e);
		quarter* bluezhen = &blue;
		quarter* redzhen = &red;
		int time = 0;
		cout<<"Case:"<<i+1<<endl;
		while(bluezhen->hainengxu() || redzhen->hainengxu()){
			red.shengchan(time);
			blue.shengchan(time);
			time++;
			}
		red.shengchan(time);
		blue.shengchan(time);
	}

	return 0;
}






















