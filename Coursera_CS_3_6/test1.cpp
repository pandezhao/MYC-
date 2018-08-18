#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
using namespace std;

class time{
	int shi;
	public:	
		int fen;
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
		void terminate(string color){
			fen = 5000;
			int tmp = zhanshi();
			cout<<color<<" headquarter was taken"<<endl;
		}
};
time timer;

int R;
int K;
class weapon{
	public:
		weapon(){}
		virtual weapon_attack()=0;
		virtual get_name()=0;
		virtual void baogaowuqi_child_child()=0;
};
class sword:public weapon(){
	int sword_attack;
	bool broken;
	string name="sword";
	public:
		friend warrior;
		sword(int a):weapon(){
			sword_attack = a;
			broken = false;
		}
		virtual int weapon_attack(){
			int tmp = sword_attack;
			sword_attack = 0.8 * sword_attack;
			if (sword_attack == 0){
				broken = true;
			}
			return tmp;
		}
		virtual string get_name(){
			return name;
		}
		virtual void baogaowuqi_child_child(){
			cout<<"sword("<<sword_attack<<')';
		}
};

class bomb:public weapon(){ //  试试等一下，一会再接着写
	string name="bomb";
	public:
		virtual int weapon_attack(){
			return 0;
		}
		virtual string get_name(){
			return name;
		}
		virtual void baogaowuqi_child_child(){
			cout<<"bomb";
		}
};

class arrow:public weapon(){
	int arrow_attack;
	int times;
	string name="arrow";
	public:
		friend warrior;
		arrow():weapon(){
			arrow_attack = R;
			times = 3;
		}
		virtual int weapon_attack(){
			if (times!=0){
				times --
				return arrow_attack;
				}
		}
		virtual string get_name(){
			return name;
		}
		virtual void baogaowuqi_child_child(){
			cout<<"arrow("<<times<<')';
		}
};

weapon& which_weapon(int Index, int attack, int arrow_attack){
	if (Index % 3 == 0){
		sword tmp(0.8*attack);
		return tmp;
	}else if(Index % 3 == 1){
		bomb tmp();
		return tmp;
	}else if(Index % 3 == 2){
		arrow tmp(arrow_attack)
		return tmp;
	}
} 

class warrior{
	int index;
	string color;
	int life;
	int attack;
	public:
		friend dragon;
		friend ninja;
		friend iceman;
		friend lion;
		friend wolf;
		friend city;
		warrior(int a, int b, int c, string d){
			index = a;
			life = b;
			attack = c;
			string color = d;
		}
		virtual void attack()=0;
		virtual bool defance()=0;
		virtual void huanhu()=0;
		virtual bool qingzhen()=0; //使用炸弹自爆
		virtual void fight_back()=0;	
		virtual string get_name()=0;
		virtual bool has_weapon()=0;
		int get_life(){
			return life;
		}
		int get_attack(){
			return attack;
		}
		string get_color(){
			return color;
		}
		void warrior_jiaxue(){
			life+= 8;
		}
		int get_index(){
			return index;
		}
		virtual void baogaowuqi_child()=0;
};

class dragon:public warrior{
	float morale;
	bool flag=false;
	weapon* one;
	string name = "dragon";
	public:
		friend city;
		dragon(int Index_a,int life_b,int attack_c,string color_d,float e):warrior(Index_a,life_b,attack_c,color_d),morale(e){
			weapon_one = which_weapon(Index_a, attack_c, ); // 还没解决弓箭的变量的问题 ！！！！！！！！！！
			one = &weapon_one;
		}
		virtual bool qingzhen(const warrior* enemy){
			if (one!=NULL&&one->get_name() == "bomb" && enemy.get_attack()>get_life()){
				enemy->defance(NULL);
				warrior::life = 0;
				return true;
			}
			else{return false;}
		}
		virtual void attack(const warrior* enemy){
			if (one!=NULL&&one->get_name() == "sword"){
				if (enemy->defance(warrior::get_attack()+one->weapon_attack())){
					flag = true;	
					morale += 0.2;	
				}
				else{morale-=0.2;}
			}
			else{
			enemy->defance(warrior::get_attack());}
		}
		
		virtual bool shot(warrior* enemy){  // 使用弓箭攻击敌人
			if (one->get_name=="arrow"){
				if (enemy -> defance(tmp->weapon_attack())){
					if (two->times==0){
						delete two;
						two == NULL;
					}
					return true;
				}
				else{
					if (tmp->times==0){
						delete tmp;
						tmp == NULL;
					}
					return false;
				}

			}		
		}


		virtual fight_back(const warrior* enemy){
			if (warrior::life>0){
				if(one->get_name() == "sword"){
					enemy->defance(0.5 * warrior::attack + one->weapon_attack())
				}else{enemy->defance(0.5 * warrior::attack)}
			}
		}
		virtual bool has_weapon(string tmp){ //拥有指定的武器么？
			if (one->get_name()==tmp){return true;}
			else 
				return false;
		}
		virtual bool defance(int damage){
			if (damage == NULL){
				warrior::life = 0;
				return true;
			}
			else{
				life -= damage; 
				if(life<0){return true;}
				else{return false;}
			}
		}
		virtual void huanhu(){
			if (flag && morale>0.8){
			cout<<"huanhu" <<endl;
			}
			flag = false;
		}
		virtual string get_name(){
			return name;
		}
		virtual void baogaowuqi_child(){
			cout<<"dragon "<<warrior::get_index()<<" has ";
			if (one==NULL){
				cout<<"no weapon"<<endl;				
			}else{
				one->baogaowuqi_child_child();
				cout<<endl;
			}
		}
};

class ninja:public warrior{
	weapon* one;
	weapon* two;
	string name = "ninja";
	public:
		friend city;
		ninja(int Index_a,int life_b,int attack_c,string color_d):warrior(Index_a,life_b,attack_c,color_d){
			weapon_one = which_weapon(Index_a, attack_c, );
			weapon_two = which_weapon(Index_a+1, attack_c, );
			one = &weapon_one;
			two = &weapon_two;
		}
		virtual bool qingzhen(const warrior* enemy){
			if ((one!=NULL||two!=NULL)&&(one->get_name() == "bomb"||two->get_name()=="bomb")&&enemy.get_attack()>get_life()){
				enemy->defance(NULL);
				warrior::life = 0;
				return true;
			}
			else{return false;}
		}
		virtual bool has_weapon(string tmp){ //拥有指定的武器么？
			if (one->get_name()==tmp || two->get_name()==tmp){return true;}
			else 
				return false;
		}
		virtual fight_back(const warrior* enemy){
			if (warrior::life>0){
				if(one->get_name() == "sword"){
					enemy->defance(0.5 * warrior::attack + one->weapon_attack())
				}
				else if(two->get_name() == "sword"){
					enemy->defance(0.5 * warrior::attack + two->weapon_attack())
				}else{enemy->defance(0.5 * warrior::attack)}
			}
		}
		virtual void attack(const warrior* enemy){
			if (one!=NULL&&one->get_name()=="sword"){
				enemy->defance(warrior::get_attack()+one->weapon_attack());
			}
			else if (two!=NULL&&two->get_name()=="sword"){
				enemy->defance(warrior::get_attack()+two->weapon_attack());
			}
			else{
				enemy->defance(warrior::get_attack());
			}		
		}

		virtual bool shot(warrior* enemy){  // 使用弓箭攻击敌人
			if (one->get_name=="arrow"){
				if (enemy -> defance(tmp->weapon_attack())){
					if (two->times==0){
						delete two;
						two == NULL;
					}
					return true;
				}
				else{
					if (tmp->times==0){
						delete tmp;
						tmp == NULL;
					}
					return false;
				}

			}
			else if (two->get_name=="arrow"){
				if (enemy -> defance(tmp->weapon_attack())){
					if (two->times==0){
						delete two;
						two == NULL;
					}
					return true;
				}
				else{
					if (tmp->times==0){
						delete tmp;
						tmp == NULL;
					}
					return false;
				}
			}			
		}

		virtual bool defance(int damage){
			if (damage == NULL){
				warrior::life = 0;
				return true;
			}
			else{
				life -= damage; 
				if(life<0){return true;}
				else{return false;}
			}
		}
		virtual string get_name(){
			return name;
		}
		virtual void baogaowuqi_child(){
			cout<<"ninja "<<warrior::get_index()<<" has ";
			if (one==NULL&&two==NULL){
				cout<<"no weapon"<<endl;				
			}else if(one==NULL&&two!=NULL){
				two->baogaowuqi_child_child();
				cout<<endl;
			}else if(one!=NULL&&two==NULL){
				two->baogaowuqi_child_child();
				cout<<endl;
			}else{
				if(one->get_name()=="arrow"){
					one->baogaowuqi_child_child();
					cout<<endl;
				}
				if(two->get_name()=="arrow"){
					two->baogaowuqi_child_child();
					cout<<endl;
				}
				if(one->get_name()=="bomb"){
					one->baogaowuqi_child_child();
					cout<<endl;
				}
				if(two->get_name()=="bomb"){
					two->baogaowuqi_child_child();
					cout<<endl;
				}
				if(one->get_name()=="sword"){
					one->baogaowuqi_child_child();
					cout<<endl;
				}
				if(two->get_name()=="sword"){
					two->baogaowuqi_child_child();
					cout<<endl;
				}
			}
		}
};

class iceman:public warrior{
	weapon *one;
	int bushu=0;
	string name = "iceman";
	public:
		friend city;
		iceman(int Index_a,int life_b,int attack_c,string color_d):warrior(Index_a,life_b,attack_c,color_d){
			weapon_one = which_weapon(Index_a, attack_c, );
			one = &weapon_one;
		}
		virtual void ronghua(){
			bushu++;
			if (bushu>1){
				warrior::life-=9;
				if (warrior::life<1){
					warrior::life = 1;
				}
				warrior::attack+=20;
				bushu=0;
			}
		}
		virtual bool has_weapon(string tmp){ //拥有指定的武器么？
			if (one->get_name() == tmp){return true;}
			else 
				return false;
		}
		
		virtual bool shot(warrior* enemy){  // 使用弓箭攻击敌人
			if (one->get_name=="arrow"){
				if (enemy -> defance(tmp->weapon_attack())){
					if (two->times==0){
						delete two;
						two == NULL;
					}
					return true;
				}
				else{
					if (tmp->times==0){
						delete tmp;
						tmp == NULL;
					}
					return false;
				}

			}			
		}
	
		
		virtual fight_back(const warrior* enemy){
			if (warrior::life>0){
				if(one->get_name() == "sword"){
					enemy->defance(0.5 * warrior::attack + one->weapon_attack())
				}else{enemy->defance(0.5 * warrior::attack)}
			}
		}
		virtual bool qingzhen(const warrior* enemy){
			if (one!=NULL&&one->get_name() == "bomb" && enemy.get_attack()>get_life()){
				enemy->defance(NULL);
				warrior::life = 0;
				return true;
			}
			else{return false;}
		}
		virtual void attack(const warrior* enemy){
			if (one!=NULL&&one->get_name() == "sword"){
				enemy->defance(warrior::get_attack()+one->weapon_attack());
			}
			else{
			enemy->defance(warrior::get_attack());}
		}
		virtual bool defance(int damage){
			if (damage == NULL){
				warrior::life = 0;
				return true;
			}
			else{
				life -= damage; 
				if(life<0){return true;}
				else{return false;}
			}
		}
		virtual string get_name(){
			return name;
		}
		virtual void baogaowuqi_child(){
			cout<<"iceman "<<warrior::get_index()<<" has ";
			if (one==NULL){
				cout<<"no weapon"<<endl;				
			}else{
				one->baogaowuqi_child_child();
				cout<<endl;
			}
		}
};

class lion:public warrior{
	int loyalty;
	string name = "lion";
	public:
		friend city;
		lion(int Index_a,int life_b,int attack_c,string color_d, int remain_life):warrior(Index_a,life_b,attack_c,color_d){
			loyalty = remain_life;
		}
		virtual void attack(const warrior* enemy){
			if(enemy->defance(warrior::get_attack())){
			}
			else{loyalty-=K;}
		}
		virtual fight_back(const warrior* enemy){
			if (warrior::life>0){
				enemy->defance(0.5 * warrior::attack);
			}
		}

		virtual bool has_weapon(string tmp){ //拥有指定的武器么？
			return false;
		}

		virtual bool defance(int damage){
			if (damage == NULL){
				warrior::life = 0;
				return true;
			}
			else{
				life -= damage; 
				if(life<0){return true;}
				else{return false;}
			}
		}
		virtual string get_name(){
			return name;
		}
		bool escape(){
			if (loyalty<=0){return true;}
			else
				return false;
		}
		virtual void baogaowuqi_child(){
			cout<<"lion "<<warrior::get_index()<<" has no weapon"<<endl;
		}
};

class wolf:public warrior{
	sword * one=NULL;
	arrow *	two=NULL;
	string name = "wolf";
	public:
		friend city;
		wolf(int Index_a,int life_b,int attack_c,string color_d):warrior(Index_a,life_b,attack_c,color_d){
		}
		virtual void attack(const warrior* enemy){
			if(enemy->defance(warrior::get_attack())){
				if (enemy.get_name() == "iceman"){

				}
				else if (enemy.get_name() == "wolf"){
					if (enemy.one!=NULL && one==NULL){
						one = enemy.one;
					}
					if (enemy.two!=NULL && two==NULL){
						two = enemy.two;
					}
				}
				else if (enemy.get_name() == "ninja"){
	
				}
				else if (enemy.get_name() == "dragon"){

				}	
			}
		}
		virtual bool has_weapon(string tmp){ //拥有指定的武器么？
			if (one->get_name()==tmp || two->get_name()==tmp){return true;}
			else 
				return false;
		}

		virtual bool shot(warrior* enemy){
			if (two!=NULL){			
				if (enemy -> defance(two->weapon_attack())){
					if (two->times==0){
						delete two;
						twp == NULL;
					}
					return true;
				}
				else{
					if (two->times==0){
						delete two;
						twp == NULL;
					}
					return false;
				}				
			}
		}
		virtual fight_back(const warrior* enemy){
			if (warrior::life>0){
				enemy->defance(0.5 * warrior::attack);
			}
		}
		virtual bool defance(int damage){
			if (damage == NULL){
				warrior::life = 0;
				return true;
			}
			else{
				life -= damage; 
				if(life<0){return true;}
				else{return false;}
			}
		}
		virtual string get_name(){
			return name;
		}
		virtual void baogaowuqi_child(){
			cout<<"wolf "<<warrior::get_index()<<" has ";
			if (one==NULL&&two==NULL){
				cout<<"no weapon"<<endl;				
			}else if(one==NULL&&two!=NULL){
				two->baogaowuqi_child_child();
				cout<<endl;
			}else if(one!=NULL&&two==NULL){
				two->baogaowuqi_child_child();
				cout<<endl;
			}else{
				if(one->get_name()=="arrow"){
					one->baogaowuqi_child_child();
					cout<<endl;
				}
				if(two->get_name()=="arrow"){
					two->baogaowuqi_child_child();
					cout<<endl;
				}
				if(one->get_name()=="bomb"){
					one->baogaowuqi_child_child();
					cout<<endl;
				}
				if(two->get_name()=="bomb"){
					two->baogaowuqi_child_child();
					cout<<endl;
				}
				if(one->get_name()=="sword"){
					one->baogaowuqi_child_child();
					cout<<endl;
				}
				if(two->get_name()=="sword"){
					two->baogaowuqi_child_child();
					cout<<endl;
				}
			}
		}
};

class city{
	int life;
	int index;
	string flag=NULL;
	int red_victory=0;
	int blue_victory=0;
	warrior* red_warrior=NULL;
	warrior* blue_warrior=NULL;

	warrior* red_warrior_tmp=NULL;
	warrior* blue_warrior_tmp=NULL;

	bool red_zhansi=false;
	bool blue_zhansi=false;

	city* shang=NULL;
	city* xia=NULL;
	public:
		friend game;
		city(int Index,int a=0,warrior* r=NULL,warrior* b=NULL){
			index = Index;			
			life = a;
			red_warrior = r;
			blue_warrior = b;
		};
		void set_shang(city* tmp){
			shang = tmp;
		}
		void set_xia(city* tmp){
			xia = tmp;
		}
		void lion_escape(){
			if(red_warrior -> get_name() == "lion" && red_warrior -> escape()){
				delete red_warrior;
				red_warrior = NULL;
			}
		}
		virtual void warrior_march(){ // 武士位移，位移的部分可能还存在隐形的问题没有解决。尤其是蓝色位移。
			if (red_warrior!=NULL){
				xia->red_warrior_tmp = red_warrior;
			}
			if (red_warrior_tmp!=NULL){		
				red_warrior = red_warrior_tmp;
				red_warrior_tmp = NULL;
			}
			if (xia->blue_warrior!=NULL){
				blue_warrior = xia->blue_warrior;
			}
		}
	
		virtual void arrow_shot(){
			bool tmp1;
			bool tmp2;
			if (red_warrior!=NULL && xia->blue_warrior!=NULL && red_warrior->has_weapon("arrow")){
				bool tmp1 = red_warrior->shot(xia->blue_warrior);
			}	
			if (blue_warrior!=NULL && shang->red_warrior!=NULL && blue_warrior->has_weapon("arrow")){
				bool tmp2 = blue_warrior->shot(shang->red_warrior);
			}
			if (tmp1){ 
				delete xia->blue_warrior;
				xia->blue_warrior = NULL;
			}
			if (tmp2){
				delete shang->red_warrior;
				shang->red_warrior = NULL;
			}
		}

		virtual void warrior_qingzhen(){
			bool tmp1;
			bool tmp2;
			if (red_warrior!=NULL && red_warrior->has_weapon("bomb")){
				tmp1 = red_warrior->qingzhen(blue_warrior);
			}
			if (blue_warrior!=NULL && blue_warrior->has_weapon("bomb")){
				tmp2 = blue_warrior->qingzhen(red_warrior);
			}
			if (tmp1){}
			if (tmp2){}
		}

		virtual void warrior_attack(){
			if (flag!=NULL){
				if(flag="red"){
					red_warrior->attack(blue_warrior);
				}else if(flag="blue"){
					blue_warrior->attack(red_warrior);
				}
			}
			else{
				if (index%2==1){
					red_warrior->attack(blue_warrior);
				}
				else{
					blue_warrior->attack(red_warrior);
				}
			}
		}

		virtual void warrior_fanji(){
			if (flag!=NULL){
				if(flag="blue" && red_warrior->warrior::get_life()>0){
					red_warrior->fight_back(blue_warrior);
				}else if(flag="red" && blue_warrior->warrior::get_life()>0){
					blue_warrior->fight_back(red_warrior);
				}
			}
			else{
				if (index%2==0 && red_warrior->warrior::get_life()>0){
					red_warrior->fight_back(blue_warrior);
				}
				else if (blue_warrior->warrior::get_life()>0){
					blue_warrior->fight_back(red_warrior);
				}
			}
		}

		virtual void warrior_zhansi(){
			if (red_warrior!=NULL && blue_warrior!=NULL){
				if (red_warrior->warrior::get_life()<=0){
					delete red_warrior;
					red_warrior = NULL;
					red_zhansi = true;
					red_victory ++;
					blue_victory = 0;
				}else{
					red_zhansi = false;
				}
				if (blue_warrior->warrior::get_life()<=0){
					delete blue_warrior;
					blue_warrior = NULL;
					blue_zhansi = true;
					blue_victory ++;
					red_victory = 0;
				}else{
					blue_zhansi = false;
				}
			}
		}
		virtual void warrior_jiaxue_red(){ // 堡垒加血的部分还没有写出来
			if (blue_warrior->warrior::get_life()<=0 && red_quarter){
	
			}else{

			}
		}

		virtual void warrior_jiaxue_blue(){
			if (red_warrior->warrior::get_life()<=0 && blue_quarter){
				
			}else{}
		}
		virtual void warrior_huanhu(){
			if (red_warrior->get_name()=="dragon"){
				red_warrior->huanhu();
			}
			if (blue_warrior->get_name()=="dragon"){
				blue_warrior->huanhu();
			}
		}

		void panduan_flag(){
			if (flag=NULL){
				if(red_victory==2){
					flag="red";
					red_victory=0;
				}else if(blue_victory==2){
					flag="blue";
					blue_victory=0;
				}
			}else if(flag=="red" && blue_victory==2){
				flag=NULL;
				blue_victory=0;
			}else if(flag=="blue" && red_victory==2){
				flag=NULL;
				red_victory=0; 
			}
		}
		virtual void produce_warrior()=0;

		virtual void quarter_baogaoxueliang()=0;

		void city_baogaowuqi_red(){
			if(red_warrior!=NULL){
				timer.zhanshi();
				red_warrior->baogaowuqi_child();
			}
		}
		void city_baogaowuqi_blue(){
			if(blue_warrior!=NULL){
				timer.zhanshi();
				blue_warrior->baogaowuqi_child();
			}
		}
};

class blue_quarter:public city{
	int quarter_life;
	int flag = 4;

	int dragon_life;
	int dragon_attack;

	int ninja_life;
	int ninja_attack;

	int iceman_life;
	int iceman_attack;
	
	int lion_life;
	int lion_attack;
	
	int wolf_life;
	int wolf_attack;

	int Index=1;
	public:
		friend game;
		blue_quarter(int index,int life,int dra_life,int dra_attack,int nin_life,int nin_attack,int ice_life,int ice_attack,int lio_life,int lio_attack,int wol_life,int wol_attack):city(index){
			quarter_life = life;
			dragon_life=dra_life;
			dragon_attack=dra_attack;
			ninja_life=nin_life;
			ninja_attack=nin_attack;
			iceman_life=ice_life;
			iceman_attack=ice_attack;
			lion_life=lio_life;
			lion_attack=lio_attack;
			wolf_life=wol_life;
			wolf_attack=wol_attack;
		}
		virtual void warrior_march(){
			if (city::blue_warrior!=NULL){
				city::blue_warrior=NULL;
			}
			if (city::red_warrior_tmp!=NULL){
				if(city::red_warrior==NULL){// no stop
					city::red_warrior=city::red_warrior_tmp;
					tmp = timer.zhanshi();
					cout<<" blue "<<city::xia->blue_warrior->get_name()<<' '<<city::xia->blue_warrior->get_index()<<' '<<"reached red headquarter with ";
					cout<<city::xia->blue_warrior->get_life()<<"elements and force "<<city::xia->blue_warrior->get_attack();
				}else{//stop
					tmp = timer.zhanshi();
					cout<<" red "<<city::shang->red_warrior->get_name()<<' '<<city::shang->red_warrior->get_index()<<' '<<"reached blue headquarter with ";
					cout<<city::shang->red_warrior->get_life()<<"elements and force "<<city::shang->red_warrior->get_attack();
					timer.terminate("blue");
				}
			}
		}
		virtual void produce_warrior(int time){
			switch(flag){
			case 1:
				if (zhizao_dragon()){
					flag = 2;
					break;
				}else if(hainengxu()){
					flag = 2;
					produce_warrior();
					break;
				}
				else{
					break;
				}
			case 2:
				if (zhizao_ninja()){
					flag = 3;
					break;
				}else if(hainengxu()){
					flag = 3;
					produce_warrior();
					break;
				}
				else{
					break;
				}

			case 3:
				if (zhizao_iceman()){
					flag = 5;
					break;
				}else if(hainengxu()){
					flag = 5;
					produce_warrior();
					break;
				}
				else{
					break;
				}
			case 4:
				if (zhizao_lion()){
					flag = 1;
					break;
				}else if(hainengxu()){
					flag = 1;
					produce_warrior();
					break;
				}
				else{
					break;
				}
			case 5:
				if (zhizao_wolf()){
					flag = 4;
					break;
				}else if(hainengxu()){
					flag = 4;
					produce_warrior();
					break;
				}
				else{
					break;
				}
			}
		}
		void zhizao_dragon(){
			float tmp = quarter_life/dragon_life;
			quarter_life -= dragon_life;
			dragon A_dragon(Index,dragon_life,dragon_attack,"blue",tmp);
			city::blue_warrior = &A_dragon;
			Index++;
		}
		void zhizao_ninja(){
			quarter_life -= ninja_life;
			ninja A_ninja(Index,ninja_life,ninja_attack,"blue");
			city::blue_warrior = &A_ninja;
			Index++;
		}
		void zhizao_iceman(){
			quarter_life -= iceman_life;
			iceman A_iceman(Index,iceman_life,iceman_attack,"blue");
			city::blue_warrior = &A_iceman;
			Index++;
		}
		void zhizao_lion(){
			quarter_life -= lion_life;
			lion A_lion(Index,lion_life,lion_attack,"blue",quarter_life);
			city::blue_warrior = &A_lion;
			Index++;
		}
		void zhizao_wolf(){
			quarter_life -= wolf_life;
			wolf A_wolf(Index,wolf_life,wolf_attack,"blue");
			city::blue_warrior = &A_wolf;
			Index++;
		}
		virtual void arrow_shot(){
			
		}
		virtual void warrior_qingzhen(){

		}
		virtual void warrior_attack(){

		}
		virtual void warrior_fanji(){

		}
}

class red_quarter:public city{
	int quarter_life;
	int flag = 3;

	int dragon_life;
	int dragon_attack;

	int ninja_life;
	int ninja_attack;

	int iceman_life;
	int iceman_attack;
	
	int lion_life;
	int lion_attack;
	
	int wolf_life;
	int wolf_attack;

	public:
		friend game;
		red_quarter(int index,int life,int dra_life,int dra_attack,int nin_life,int nin_attack,int ice_life,int ice_attack,int lio_life,int lio_attack,int wol_life,int wol_attack):city(index){
			quarter_life = life;
			dragon_life=dra_life;
			dragon_attack=dra_attack;
			ninja_life=nin_life;
			ninja_attack=nin_attack;
			iceman_life=ice_life;
			iceman_attack=ice_attack;
			lion_life=lio_life;
			lion_attack=lio_attack;
			wolf_life=wol_life;
			wolf_attack=wol_attack;
		}

		virtual void produce_warrior(int time){
			switch(flag){
			case 1:
				if (zhizao_dragon()){
					flag = 3;
					break;
				}else if(hainengxu()){
					flag = 3;
					produce_warrior();
					break;
				}
				else{
					break;
				}
			case 2:
				if (zhizao_ninja()){
					flag = 1;
					break;
				}else if(hainengxu()){
					flag = 1;
					produce_warrior();
					break;
				}
				else{
					break;
				}

			case 3:
				if (zhizao_iceman()){
					flag = 4;
					break;
				}else if(hainengxu()){
					flag = 4;
					produce_warrior();
					break;
				}
				else{
					break;
				}
			case 4:
				if (zhizao_lion()){
					flag = 5;
					break;
				}else if(hainengxu()){
					flag = 5;
					produce_warrior();
					break;
				}
				else{
					break;
				}
			case 5:
				if (zhizao_wolf()){
					flag = 2;
					break;
				}else if(hainengxu()){
					flag = 2;
					produce_warrior();
					break;
				}
				else{
					break;
				}
			}
		virtual void warrior_march(){ 
			if (city::red_warrior!=NULL){
				city::xia->red_warrior_tmp = city::red_warrior;
			}
			if (city::xia->blue_warrior!=NULL){
				if (city::blue_warrior==NULL){
					city::blue_warrior = city::xia->blue_warrior;
					tmp = timer.zhanshi();
					cout<<" blue "<<city::xia->blue_warrior->get_name()<<' '<<city::xia->blue_warrior->get_index()<<' '<<"reached red headquarter with ";
					cout<<city::xia->blue_warrior->get_life()<<"elements and force "<<city::xia->blue_warrior->get_attack();
				}else{
					tmp = timer.zhanshi();
					cout<<" blue "<<city::xia->blue_warrior->get_name()<<' '<<city::xia->blue_warrior->get_index()<<' '<<"reached red headquarter with ";
					cout<<city::xia->blue_warrior->get_life()<<"elements and force "<<city::xia->blue_warrior->get_attack();
					timer.terminate("red");
				}
			}
		}
		void zhizao_dragon(){
			float tmp = quarter_life/dragon_life;
			quarter_life -= dragon_life;
			dragon A_dragon(Index,dragon_life,dragon_attack,"red",tmp);
			city::red_warrior = &A_dragon;
			Index++;
		}
		void zhizao_ninja(){
			quarter_life -= ninja_life;
			ninja A_ninja(Index,ninja_life,ninja_attack,"red");
			city::red_warrior = &A_ninja;
			Index++;
		}
		void zhizao_iceman(){
			quarter_life -= iceman_life;
			iceman A_iceman(Index,iceman_life,iceman_attack,"red");
			city::red_warrior = &A_iceman;
			Index++;
		}
		void zhizao_lion(){
			quarter_life -= lion_life;
			lion A_lion(Index,lion_life,lion_attack,"red",quarter_life);
			city::red_warrior = &A_lion;
			Index++;
		}
		void zhizao_wolf(){
			quarter_life -= wolf_life;
			wolf A_wolf(Index,wolf_life,wolf_attack,"red");
			city::red_warrior = &A_wolf;
			Index++;
		}
		virtual void arrow_shot(){

		}
		virtual void warrior_qingzhen(){

		}
		virtual void warrior_attack(){

		}
		virtual void warrior_fanji(){

		}
}

class game{
	city **citys;
	int counter_city;

	public:
		game(int M,int N,int dragon_life,int ninja_life, int iceman_life,int lion_life,int wolf_life,int dragon_attack,int ninja_attack,int iceman_attack,int lion_attack,int wolf_attack){
			
			// 设置城市的部分
			counter_city = N+2;
			citys = new city*[N+2];
			////
			for (int ii=0;ii<(N+2);ii++){
				if (ii==0){
					red_quarter A_red_quarterint(ii,M,dragon_life,dragon_attack,ninja_life,ninja_attack,iceman_life,iceman_attack,lion_life,lion_attack,wolf_life,wolf_attack)
					citys[ii] = &A_red_quarter; // 这里是红魔军
				}
				else if (ii==N+1){
					blue_quarter A_blue_quarter(ii,M,dragon_life,dragon_attack,ninja_life,ninja_attack,iceman_life,iceman_attack,lion_life,lion_attack,wolf_life,wolf_attack)
					citys[ii] = &A_blue_quarter; // 这里是蓝魔军
				}
				else{
					city A_city(ii); // 这里是普通城市
					citys[ii] = tmp;
				}
			}
			for (int ii=0;ii<(N+2);ii++){
				if (ii==0){
					citys[ii]->city::xia = tmp_citys[ii+1];
				}
				else if (ii==N+1){
					citys[ii]->city::shang = tmp_citys[ii-1];
				}
				else{
					citys[ii]->shang = tmp_citys[ii-1];
					citys[ii]->xia = tmp_citys[ii+1];
				}
			}
		}
		void birth(){
			citys[0]->produce_warrior(time); //这里的time还没有正式赋值
			citys[counter_city-1]->produce_warrior(time); //这里的time还没有正式赋值
		} //
		void escape(){
			for (int i=0;i<counter_city;i++){
				citys[i]->lion_escape();
			}
		} //
		void march(){
			for (int i=0;i<counter_city;i++){
				citys[i]->warrior_march();
			}
		} //
		void fangjian(){
			for (int i=0;i<counter_city;i++){
				citys[i]->arrow_shot();
			}
		} //
		void qingzhen(){
			for (int i=0;i<counter_city;i++){
				citys[i]->warrior_qingzhen();
			}
		} //
		void battle(){
			for (int i=0;i<counter_city;i++){
				citys[i]->warrior_attack();
			}
		}  //
		void fanji(){
			for (int i=0;i<counter_city;i++){
				citys[i]->warrior_fanji();
			}
		} //
		void jiaxue(){
			for (int i=0;i<counter_city;i++){
				citys[i]->warrior_jiaxue_red();
				citys[counter_city-1-i]->warrior_jiaxue_blue();
			}
		} //
		void shengqi(){
			for (int i=0;i<counter_city;i++){
				citys[i]->panduan_flag();
			}
		} //
		void baogaoxueliang(){
			for (int i=0;i<counter_city;i++){
				citys[i]->city_baogaoxueliang();
			}
		} //
		void baogaowuqi(){
			for (int i=0;i<counter_city;i++){
				citys[i]->city_baogaowuqi_red();
			}
			for (int i=0;i>counter_city;i++){
				citys[counter_city-1-i]->city_baogaowuqi_blue()
			}
		} //
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

int main(){
	int t;
	cin>>t;
	int M,N,T;
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
