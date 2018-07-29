#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


class weapon{
public:
	string name;
	weapon(int bianhao){
		if (bianhao==0){name="sword";}
		else if(bianhao==1){name=="bomb";}
		else if(bianhao==2){name=="arrow";}
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
	iceman(int a,int b):warrior(a,b),one(a%3){}
};

class lion:public warrior{
int loyalty;
public:
	lion(int a,int b,int c):warrior(a,b),loyalty(c){}
};

class wolf:public warrior{

};

class ninja:public warrior{
weapon one,two;
public:
	ninja(int a,int b):warrior(a,b),one(a%3),two((a+1)%3){}
};

class dragon:public warrior{
weapon one;
float morale;
public:
	dragon(int a,int b,float c):warrior(a,b),one(a%3),morale(c){}
};


//城堡的综合类
class quarter{
private:
	int life;
	int dragon_life;
	int ninja_life;
	int iceman_life;
	int lion_life;
	int wolf;
	int index = 0;
	int dragons = 0;
	int ninjas = 0;
	int icemans = 0;
	int lions = 0;
	int wolfs = 0;

public:
	quarter(int a,int b,int c,int d,int e,int f):life(a),dragon_life(b),ninja_life(c),iceman_life(d),lion_life(e),wolf_life(f){}

	bool zhizao_dragon(string color){
		if (life>=dragon_life){
			index++;
			dragons++;
			life = life - dragon_life;
			float mor = (float)life / (float)dragon_life;
			cout<<' '<<color<<" dragon "<<index<<"born with strength "<<dragon_life<<','<<
			dragon tmp(dragon_life, index, mor);
			return true;
		}else{
			return false;
		}
	}
	bool zhizao_ninja(string color){
		if (life>=ninja_life){
			index++;
			ninjas++;
			life = life - ninja_life;
			ninja tmp(ninja_life, index);
			return true;
		}else{
			return false;
		}
	}
	bool zhizao_iceman(string color){
		if (life>=iceman_life){
			index++;
			icemans++;
			life = life - iceman_life;
			return true;
		}else{
			return false;
		}
	}
	bool zhizao_lion(string color){
		if (life>=lion_life){
			index++;
			lions++;
			life = life - lion_life;
			return true;
		}else{
			return false;
		}
	}
	bool zhizao_wolf(string color){
		if (life>=wolf_life){
			index++;
			wolfs++;
			life = life - wolf_life;
			return true;
		}else{
			return false;
		}
	}
};

//蓝色城堡
class bluequarter:public quarter{
public:
	bluequarter(int a,int b,int c,int d,int e,int f):quarter(a,b,c,d,e,f){}

	void shengc
};

//红色城堡
class redquarter:public quarter{
public:
	redquarter(int a,int b,int c,int d,int e,int f):quarter(a,b,c,d,e,f){}
};

int main(){

	return 0;
}






















