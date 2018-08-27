#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
using namespace std;
class record_time{
	int shi;
	public:	
		int fen;
		record_time(){
			int shi=0;
			int fen=-1;
		}
		void reset(){
			shi=0;
			fen=-1;
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
		void zhanshi(){
			cout<<setfill('0')<<setw(3)<<shi<<':'<<setfill('0')<<setw(2)<<fen<<' ';
		}
		void terminate(string color){
			zhanshi();
			fen = 5000;
			cout<<color<<" headquarter was taken"<<endl;
		}
};
record_time timer;

int R;
int K;
class weapon{
	public:
		weapon(){}
		virtual ~weapon(){}
		virtual int weapon_attack()=0;
		virtual string get_name()=0;
		virtual void baogaowuqi_child_child()=0;

		virtual int arrow_times()=0;
		virtual bool sword_broken()=0;
};
class sword:public weapon{
	int sword_attack;
	bool broken;
	string name="sword";
	public:
		friend class warrior;
		friend class wolf;
		friend weapon* which_weapon(int Index, int attack);
		sword(int a):weapon(){
			sword_attack = a;
			if (a!=0){
				broken = false;
			}else{broken=true;}
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
		
		virtual bool sword_broken(){
			return broken;
		}
};

class bomb:public weapon{ //  试试等一下，一会再接着写
	string name="bomb";
	public:
		friend class warrior;
		friend weapon* which_weapon(int Index, int attack);
		bomb(){
		}
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

class arrow:public weapon{
	int arrow_attack;
	int times;
	string name="arrow";
	public:
		friend class warrior;
		friend class wolf;
		friend weapon* which_weapon(int Index, int attack);
		arrow():weapon(){
			arrow_attack = R;
			times = 3;
		}
		arrow(int number_times):weapon(){
			arrow_attack = R;
			times = number_times;
		}
		virtual int weapon_attack(){
			if (times!=0){
				times --;
				return arrow_attack;
				}
		}
		virtual string get_name(){
			return name;
		}
		virtual void baogaowuqi_child_child(){
			cout<<"arrow("<<times<<')';
		}

		virtual int arrow_times(){
			return times;
		}
};

weapon* which_weapon(int Index, int attack){
	if (Index % 3 == 0){
		int tmp_attack = 0.8 * attack;
		weapon* tmp = new sword(tmp_attack);
		if (tmp->sword_broken()){
			delete tmp;
			tmp = NULL;
			return NULL;
		}else{
			return tmp;
		}
	}else if(Index % 3 == 1){
		weapon* tmp = new bomb;
		return tmp;
	}else if(Index % 3 == 2){
		weapon* tmp = new arrow(R);
		return tmp;
	}
} 

class warrior{
	int index;
	string color;
	int life;
	int attack;
	public:
		friend class dragon;
		friend class ninja;
		friend class iceman;
		friend class lion;
		friend class wolf;
		friend class city;
		friend class blue_quarter;
		friend class red_quarter;
		warrior(int a, int b, int c, string d){
			index = a;
			life = b;
			attack = c;
			string color = d;
		}
		virtual ~warrior(){

		}

		virtual void Attack()=0;
		virtual bool defance()=0;
		virtual void huanhu()=0;
		virtual bool qingzhen()=0; //使用炸弹自爆
		virtual void fight_back()=0;	
		virtual string get_name()=0;
		virtual bool has_weapon()=0;
		virtual bool shot()=0;
		virtual void ronghua()=0;
		virtual bool escape()=0;
		virtual void delete_weapon()=0;
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
	weapon* one;
	string name = "dragon";
	public:
		friend class city;
		dragon(int Index_a,int life_b,int attack_c,string color_d,float e):warrior(Index_a,life_b,attack_c,color_d),morale(e){
			one = which_weapon(Index_a, attack_c); // 还没解决弓箭的变量的问题 ！！！！！！！！！！
		}
		~dragon(){
			delete one;
		}
		virtual void delete_weapon(){
			delete one;
		}
		virtual bool qingzhen(warrior* enemy){
			if (one!=NULL&&one->get_name() == "bomb" && enemy->get_attack()>=warrior::get_life()){
				enemy->defance(NULL);
				warrior::life = 0;
				delete one;
				return true;
			}
			else{return false;}
		}
		virtual void Attack(warrior* enemy){
			if (one!=NULL&&one->get_name() == "sword"){
				if (enemy->defance(warrior::get_attack()+one->weapon_attack())){
					morale += 0.2;	
				}
				else{morale-=0.2;}
				if (one->sword_broken()){
					delete one;
					one = NULL;
				}
			}
			else{
				if (enemy->defance(warrior::get_attack())){
					morale += 0.2;
				}
				else{morale-=0.2;}
			}
		}
		
		virtual bool shot(warrior* enemy){  // 使用弓箭攻击敌人
			if (one->get_name()=="arrow"){
				if (enemy -> defance(one->weapon_attack())){
					if (one->arrow_times()==0){
						delete one;
						one == NULL;
					}
					return true;
				}
				else{
					if (one->arrow_times()==0){
						delete one;
						one == NULL;
					}
					return false;
				}

			}
			else{return false;}	
		}

		virtual void fight_back(warrior* enemy){
			if (warrior::life>0){
				if(one!=NULL && one->get_name() == "sword"){
					if (one->sword_broken()==false){
						bool tmp = enemy->defance(0.5 * warrior::attack + one->weapon_attack());
						if (one->sword_broken()){
							delete one;
							one = NULL;
						}
					}
					else{
						bool tmp = enemy->defance(0.5 * warrior::attack);
						delete one;
						one=NULL;
					}
				}else{
					enemy->defance(0.5 * warrior::attack);
				}
			}
		}
		virtual bool has_weapon(string tmp){ //拥有指定的武器么？
			if (one!=NULL && one->get_name()==tmp){return true;}
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
				if(life<=0){return true;}
				else{return false;}
			}
		}
		virtual void huanhu(string color, int city_index){
			if (morale>0.8 && warrior::life >=0){
				timer.zhanshi();
				cout<<color<<" dragon "<<warrior::index<<" yelled in city "<<city_index<<endl;
			}
		}
		virtual string get_name(){
			return name;
		}
		virtual void baogaowuqi_child(){
			timer.zhanshi();
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
		friend class city;
		ninja(int Index_a,int life_b,int attack_c,string color_d):warrior(Index_a,life_b,attack_c,color_d){
			one = which_weapon(Index_a, attack_c);
			two = which_weapon(Index_a+1, attack_c);
		}
		~ninja(){
			delete one;
			delete two;
		}
		virtual void delete_weapon(){
			delete one;
			delete two;
		}
		virtual bool qingzhen(warrior* enemy){
			if ((one!=NULL && one->get_name()=="bomb")||(two!=NULL && two->get_name() == "bomb")&&enemy->get_attack()>=warrior::life){
				enemy->defance(NULL);
				warrior::life = 0;
				return true;
			}
			else{return false;}
		}
		virtual bool has_weapon(string tmp){ 
			if ((one!=NULL && one->get_name()==tmp) || (two!=NULL && two->get_name()==tmp)){return true;}
			else 
				return false;
		}
		virtual void fight_back(warrior* enemy){
			//if (warrior::life>0){
			//	if(one!=NULL && one->get_name() == "sword" && one->broken==false){
			//		enemy->defance(0.5 * warrior::attack + one->weapon_attack());
			//		if (one->broken==true){
			//			delete one;
			//			one = NULL;
			//		}
			//	}
			//	else if(two!=NULL && two->get_name() == "sword" && two->broken==false)
			//	{	enemy->defance(0.5 * warrior::attack + two->weapon_attack());
			//		if (two->broken==true){
			//			delete two;
			//			two = NULL;
			//		}
			//	}else{enemy->defance(0.5 * warrior::attack);}
			//}
		}
		virtual void Attack(warrior* enemy){
			if (one!=NULL&&one->get_name()=="sword"){
				enemy->defance(warrior::get_attack()+one->weapon_attack());
				if (one->sword_broken()==true){
					delete one;
					one = NULL;
				}
			}
			else if (two!=NULL&&two->get_name()=="sword"){
				enemy->defance(warrior::get_attack()+two->weapon_attack());
				if (two->sword_broken()==true){
					delete two;
					two = NULL;
				}
			}
			else{
				enemy->defance(warrior::get_attack());
			}		
		}

		virtual bool shot(warrior* enemy){ 
			if (one != NULL && one->get_name()=="arrow"){
				if (enemy -> defance(one->weapon_attack())){
					if (one->arrow_times()==0){
						delete one;
						one == NULL;
					}
					return true;
				}
				else{
					if (one->arrow_times()==0){
						delete one;
						one == NULL;
					}
					return false;
				}

			}
			else if (two != NULL && two->get_name()=="arrow"){
				if (enemy -> defance(two->weapon_attack())){
					if (two->arrow_times()==0){
						delete two;
						two == NULL;
					}
					return true;
				}
				else{
					if (two->arrow_times()==0){
						delete two;
						two == NULL;
					}
					return false;
				}
			}
			else{
				return false;
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
			timer.zhanshi();
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
				if(one->get_name()=="arrow"||two->get_name()=="arrow"){
					if(one->get_name()=="arrow"){
						one->baogaowuqi_child_child();
						cout<<',';
						two->baogaowuqi_child_child();
						cout<<endl;
					}
					else if(two->get_name()=="arrow"){
						two->baogaowuqi_child_child();
						cout<<',';
						one->baogaowuqi_child_child();
						cout<<endl;
					}
				}
				else{
					if(one->get_name()=="bomb"){
						one->baogaowuqi_child_child();
						cout<<',';
						two->baogaowuqi_child_child();
					}
					else if(two->get_name()=="bomb"){
						two->baogaowuqi_child_child();
						cout<<',';
						one->baogaowuqi_child_child();
					}
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
		friend class city;
		iceman(int Index_a,int life_b,int attack_c,string color_d):warrior(Index_a,life_b,attack_c,color_d){
			one = which_weapon(Index_a, attack_c );
		}
		~iceman(){
			delete one;
		}
		virtual void delete_weapon(){
			delete one;
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
			if (one!=NULL && one->get_name() == tmp){return true;}
			else 
				return false;
		}
		
		virtual bool shot(warrior* enemy){  // 使用弓箭攻击敌人
			if (one!=NULL && one->get_name()=="arrow"){
				if (enemy -> defance(one->weapon_attack())){
					if (one->arrow_times()==0){
						delete one;
						one == NULL;
					}
					return true;
				}
				else{
					if (one->arrow_times()==0){
						delete one;
						one == NULL;
					}
					return false;
				}

			}else{return false;}		
		}
	
		
		virtual void fight_back(warrior* enemy){
			if (warrior::life>=0){
				if(one != NULL && one->get_name() == "sword"){
					enemy->defance(0.5 * warrior::attack + one->weapon_attack());
				}else{enemy->defance(0.5 * warrior::attack);}
			}
		}
		virtual bool qingzhen(warrior* enemy){
			if (one!=NULL&&one->get_name() == "bomb" && enemy->get_attack()>get_life()){
				enemy->defance(NULL);
				warrior::life = 0;
				delete one;
				one = NULL;
				return true;
			}
			else{return false;}
		}
		virtual void Attack(warrior* enemy){
			if (one!=NULL&&one->get_name() == "sword"){
				enemy->defance(warrior::get_attack()+one->weapon_attack());
				if (one->sword_broken()==true){
					delete one;
					one = NULL;
				}
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
				if(life<=0){return true;}
				else{return false;}
			}
		}
		virtual string get_name(){
			return name;
		}
		virtual void baogaowuqi_child(){
			timer.zhanshi();
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
		friend class city;
		lion(int Index_a,int life_b,int attack_c,string color_d, int remain_life):warrior(Index_a,life_b,attack_c,color_d){
			loyalty = remain_life;
		}
		virtual void delete_weapon(){
		}
		virtual void Attack(warrior* enemy){
			if(enemy->defance(warrior::get_attack())){
			}
			else{loyalty-=K;}
		}
		virtual void fight_back(warrior* enemy){
			if (warrior::life>=0){
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
				if(life<=0){return true;}
				else{return false;}
			}
		}
		virtual string get_name(){
			return name;
		}
		virtual bool escape(){
			if (loyalty<=0){return true;}
			else
				return false;
		}
		virtual void baogaowuqi_child(){
			timer.zhanshi();
			cout<<"lion "<<warrior::get_index()<<" has no weapon"<<endl;
		}
};

class wolf:public warrior{
	sword * one=NULL;
	arrow *	two=NULL;
	string name = "wolf";
	public:
		friend class city;
		wolf(int Index_a,int life_b,int attack_c,string color_d):warrior(Index_a,life_b,attack_c,color_d){
		}
		~wolf(){
			delete one;
			delete two;
		}
		virtual void delete_weapon(){
			delete one;
			delete two;
		}
		virtual void Attack(warrior* enemy){
			int attack_tmp;
			if (one!=NULL && one->get_name()=="sword"){
				attack_tmp = warrior::get_attack() + one->weapon_attack();
				if (one->sword_broken()){
					delete one;	
					one = NULL;
				}
			}
			else{attack_tmp = warrior::get_attack();}
			if(enemy->defance(attack_tmp)){
				if (enemy->get_name() == "iceman"){
					if(enemy->one!=NULL){
						if(enemy->one->get_name()=="sword" && one==NULL){
							int tmp = enemy->one->sword::sword_attack;
							one = new sword(tmp);
							delete enemy->one;
							enemy->one = NULL;
						}else if(enemy->one->get_name()=="arrow" && two==NULL){							
							int tmp = enemy->one->arrow::times;
							two = new arrow(tmp);
							delete enemy->one;
							enemy->one = NULL;
						}
					}
				}
				else if (enemy->get_name() == "wolf"){
					if (enemy->one!=NULL && one==NULL){
						int tmp = enemy->one->sword::sword_attack;
						one = new sword(tmp);
						delete enemy->one;
						enemy->one = NULL;
					}
					if (enemy->two!=NULL && two==NULL){
						int tmp = enemy->two->arrow::times;
						two = new arrow(tmp);
						delete enemy->two;
						enemy->two = NULL;
					}
				}
				else if (enemy->get_name() == "ninja"){
					if(enemy->one!=NULL){
						if(enemy->one->get_name()=="sword" && one==NULL){
							int tmp = enemy->one->sword::sword_attack;
							one = new sword(tmp);
							delete enemy->one;
							enemy->one = NULL;
						}else if(enemy->one->get_name()=="arrow" && two==NULL){							
							int tmp = enemy->one->arrow::times;
							two = new arrow(tmp);
							delete enemy->one;
							enemy->one = NULL;
						}
					}
					if(enemy->two!=NULL){
						if(enemy->two->get_name()=="sword" && one==NULL){
							int tmp = enemy->two->sword::sword_attack;
							one = new sword(tmp);
							delete enemy->two;
							enemy->two = NULL;
						}else if(enemy->two->get_name()=="arrow" && two==NULL){							
							int tmp = enemy->two->arrow::times;
							two = new arrow(tmp);
							delete enemy->two;
							enemy->two = NULL;
						}
					}
				}
				else if (enemy->get_name() == "dragon"){
					if(enemy->one!=NULL){
						if(enemy->one->get_name()=="sword" && one==NULL){
							int tmp = enemy->one->sword::sword_attack;
							one = new sword(tmp);
							delete enemy->one;
							enemy->one = NULL;
						}else if(enemy->one->get_name()=="arrow" && two==NULL){							
							int tmp = enemy->one->arrow::times;
							two = new arrow(tmp);
							delete enemy->one;
							enemy->one = NULL;
						}
					}
				}	
			}
		}
		virtual bool has_weapon(string tmp){ //拥有指定的武器么？
			if ((one!=NULL &&one->get_name()==tmp) || (two!=NULL && two->get_name()==tmp)){return true;}
			else 
				return false;
		}

		virtual bool shot(warrior* enemy){
			if (two!=NULL){			
				if (enemy -> defance(two->weapon_attack())){
					if (two->arrow_times()==0){
						delete two;
						two == NULL;
					}
					return true;
				}
				else{
					if (two->arrow_times()==0){
						delete two;
						two == NULL;
					}
					return false;
				}				
			}
			else{return false;}
		}
		virtual void fight_back(warrior* enemy){
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
				if(life<=0){return true;}
				else{return false;}
			}
		}
		virtual string get_name(){
			return name;
		}
		virtual void baogaowuqi_child(){
			timer.zhanshi();
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
				two->baogaowuqi_child_child();
				cout<<',';
				one->baogaowuqi_child_child();
				cout<<endl;
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
	bool fa_sheng_zhan_dou=false;

	city* shang=NULL;
	city* xia=NULL;

	red_quarter* red_quarter_city = NULL;
	blue_quarter* blue_quarter_city = NULL;
	public:
		friend class game;
		friend class blue_quarter;
		friend class red_quarter;
		city(int Index,int a=0,warrior* r=NULL,warrior* b=NULL){
			index = Index;			
			life = a;
			red_warrior = r;
			blue_warrior = b;
		};
		virtual ~city(){
			delete red_warrior_tmp;
			delete blue_warrior_tmp;
			delete red_warrior;
			delete blue_warrior;
		}
		void set_shang(city* tmp){
			shang = tmp;
		}
		void set_xia(city* tmp){
			xia = tmp;
		}
		virtual void lion_escape(){
			if(red_warrior -> get_name() == "lion" && red_warrior -> escape()){
				timer.zhanshi();
				cout<<"red lion "<<red_warrior->warrior::index<<" ran away"<<endl;
				delete red_warrior;
				red_warrior = NULL;
			}
			if(blue_warrior -> get_name() == "lion" && blue_warrior -> escape()){
				timer.zhanshi();
				cout<<"blue lion "<<blue_warrior->warrior::index<<" ran away"<<endl;
				delete blue_warrior;
				blue_warrior = NULL;
			}
		}
		virtual void warrior_march_1(){ // 武士位移，位移的部分可能还存在隐形的问题没有解决。尤其是蓝色位移。
			if (shang->red_warrior!=NULL){
				red_warrior_tmp = shang->red_warrior;
				shang->red_warrior=NULL;
				if (red_warrior_tmp->get_name()=="iceman"){
					red_warrior_tmp->ronghua();
				}
			}
			if (xia->blue_warrior!=NULL){
				blue_warrior_tmp = xia->blue_warrior;
				xia->blue_warrior=NULL;
				if (blue_warrior_tmp->get_name()=="iceman"){
					blue_warrior_tmp->ronghua();
				}
			}
		}
		virtual void warrior_march_2(){
			if (red_warrior_tmp!=NULL){
				red_warrior = red_warrior_tmp;
				red_warrior_tmp = NULL;
				timer.zhanshi();
				cout<<"red "<<red_warrior->get_name()<<' '<<red_warrior->get_index()<<" marched to city "<<index<<" with "<<red_warrior->get_life()<<" elements and force "<<red_warrior->get_attack()<<endl;
			}
			if (blue_warrior_tmp!=NULL){
				blue_warrior = blue_warrior_tmp;
				blue_warrior_tmp = NULL;
				timer.zhanshi();
				cout<<"blue "<<blue_warrior->get_name()<<' '<<blue_warrior->get_index()<<" marched to city "<<index<<" with "<<blue_warrior->get_life()<<" elements and force "<<blue_warrior->get_attack()<<endl;
			}
		}
	
		virtual void arrow_shot(){/// 我写到arrow shot这里了。 这里还未完成，等待明天早上继续
			bool tmp1=false;
			bool tmp2=false;
			if (red_warrior!=NULL && xia->blue_warrior!=NULL && red_warrior->has_weapon("arrow")){
				bool tmp1 = red_warrior->shot(xia->blue_warrior);
				if (tmp1){ 
					timer.zhanshi();
					cout<<"red "<<red_warrior->get_name()<<' '<<red_warrior->warrior::index<<" shot and killed blue "<<xia->blue_warrior->get_name()<<' '<<xia->blue_warrior->warrior::index<<endl;
					delete xia->blue_warrior;
					xia->blue_warrior = NULL;
				}else{
					timer.zhanshi();
					cout<<"red "<<red_warrior->get_name()<<' '<<red_warrior->warrior::index<<" shot"<<endl;
				}
			}	
			if (blue_warrior!=NULL && shang->red_warrior!=NULL && blue_warrior->has_weapon("arrow")){
				bool tmp2 = blue_warrior->shot(shang->red_warrior);
				if (tmp2){
					timer.zhanshi();
					cout<<"blue "<<blue_warrior->get_name()<<' '<<blue_warrior->warrior::index<<" shot and killed blue "<<shang->red_warrior->get_name()<<' '<<shang->red_warrior->warrior::index<<endl;
					delete shang->red_warrior;
					shang->red_warrior = NULL;
				}else{
					timer.zhanshi();
					cout<<"blue "<<blue_warrior->get_name()<<' '<<blue_warrior->warrior::index<<" shot"<<endl;
				}
			}
		}

		void warrior_qingzhen(){
			bool tmp1;
			bool tmp2;
			if (red_warrior!=NULL && red_warrior->has_weapon("bomb")){
				tmp1 = red_warrior->qingzhen(blue_warrior);
			}
			if (blue_warrior!=NULL && blue_warrior->has_weapon("bomb")){
				tmp2 = blue_warrior->qingzhen(red_warrior);
			}
			if (tmp1){
				timer.zhanshi();
				cout<<"red "<<red_warrior->get_name()<<' '<<red_warrior->warrior::index<<" used a bomb and killed blue "<<blue_warrior->get_name()<<blue_warrior->warrior::index<<endl;
				delete red_warrior;
				delete blue_warrior;
				red_warrior=NULL;
				blue_warrior=NULL;
			}
			if (!tmp1 && tmp2){
				timer.zhanshi();
				cout<<"blue "<<blue_warrior->get_name()<<' '<<blue_warrior->warrior::index<<" used a bomb and killed red "<<red_warrior->get_name()<<red_warrior->warrior::index<<endl;
				delete red_warrior;
				delete blue_warrior;
				red_warrior=NULL;
				blue_warrior=NULL;
			}
		}

		void warrior_attack(){
			if (red_warrior!=NULL && blue_warrior!=NULL){
				fa_sheng_zhan_dou = true;
				if (flag!=NULL){
					if(flag="red"){
						red_warrior->attack(blue_warrior);
						timer.zhanshi();
						cout<<"red "<<red_warrior->get_name()<<' '<<red_warrior->get_index()<<" attacked blue "<<blue_warrior->get_name()<<' '<<red_warrior->get_index()<<" in city "<<index<<" with "<<red_warrior->get_life()<<" elements and force "<<red_warrior->get_attack()<<endl;
					}else if(flag="blue"){
						blue_warrior->attack(red_warrior);
						timer.zhanshi();
						cout<<"blue "<<blue_warrior->get_name()<<' '<<blue_warrior->get_index()<<" attacked red "<<red_warrior->get_name()<<' '<<blue_warrior->get_index()<<" in city "<<index<<" with "<<blue_warrior->get_life()<<" elements and force "<<blue_warrior->get_attack()<<endl;
					}
				}
				else{
					if (index%2==1){
						red_warrior->attack(blue_warrior);
						timer.zhanshi();
						cout<<"red "<<red_warrior->get_name()<<' '<<red_warrior->get_index()<<" attacked blue "<<blue_warrior->get_name()<<' '<<red_warrior->get_index()<<" in city "<<index<<" with "<<red_warrior->get_life()<<" elements and force "<<red_warrior->get_attack()<<endl;
					}
					else{
						blue_warrior->attack(red_warrior);
						timer.zhanshi();
						cout<<"blue "<<blue_warrior->get_name()<<' '<<blue_warrior->get_index()<<" attacked red "<<red_warrior->get_name()<<' '<<blue_warrior->get_index()<<" in city "<<index<<" with "<<blue_warrior->get_life()<<" elements and force "<<blue_warrior->get_attack()<<endl;
					}
				}
			}
		}

		void warrior_fanji(){
			if (red_warrior!=NULL && blue_warrior!=NULL){
				if (flag!=NULL){
					if(flag="blue" && red_warrior->warrior::get_life()>0){
						red_warrior->fight_back(blue_warrior);
						if (red_warrior->get_name()!="ninja"){
							timer.zhanshi();
							cout<<"red "<<red_warrior->get_name()<<' '<<red_warrior->get_index()<<" fought back against blue "<<blue_warrior->get_name()<<' '<<blue_warrior->get_index()<<" in city "<<index<<endl;
						}
					}else if(flag="red" && blue_warrior->warrior::get_life()>0){
						blue_warrior->fight_back(red_warrior);
						if (blue_warrior->get_name()!="ninja"){
							timer.zhanshi();
							cout<<"blue "<<blue_warrior->get_name()<<' '<<blue_warrior->get_index()<<" fought back against red "<<red_warrior->get_name()<<' '<<red_warrior->get_index()<<" in city "<<index<<endl;
						}
					}
				}
				else{
					if (index%2==0 && red_warrior->warrior::get_life()>0){
						red_warrior->fight_back(blue_warrior);
						if(red_warrior->get_name()!="ninja"){
							timer.zhanshi();
							cout<<"red "<<red_warrior->get_name()<<' '<<red_warrior->get_index()<<" fought back against blue "<<blue_warrior->get_name()<<' '<<blue_warrior->get_index()<<" in city "<<index<<endl;
						}
					}
					else if (blue_warrior->warrior::get_life()>0){
						blue_warrior->fight_back(red_warrior);
						if(blue_warrior->get_name()!="ninja"){
							timer.zhanshi();
							cout<<"blue "<<blue_warrior->get_name()<<' '<<blue_warrior->get_index()<<" fought back against red "<<red_warrior->get_name()<<' '<<red_warrior->get_index()<<" in city "<<index<<endl;
						}
					}
				}
			}
		}

		void warrior_zhansi(){
			if (red_warrior!=NULL && blue_warrior!=NULL){
				if (red_warrior->warrior::get_life()<=0){
					timer.zhanshi();
					cout<<"red "<<red_warrior->get_name()<<' '<<red_warrior->get_index()<<" was killed in city "<<index<<endl;
					red_warrior->delete_weapon();
					delete red_warrior;
					red_warrior = NULL;
					red_zhansi = true;
					red_victory ++;
					blue_victory = 0;
				}else{
					red_zhansi = false;
				}
				if (blue_warrior->warrior::get_life()<=0){
					timer.zhanshi();
					cout<<"blue "<<blue_warrior->get_name()<<' '<<blue_warrior->get_index()<<" was killed in city "<<index<<endl;
					blue_warrior->delete_weapon();
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
		void warrior_jiaxue_red(city* red_quarter_city){ // 堡垒加血的部分还没有写出来
			if (blue_zhansi && red_quarter_city->quarter_life>=8){
				red_quarter_city->quarter_life-=8;
				red_warrior->life+=8;
				blue_zhansi = false;
			}else{
				blue_zhansi = false;
			}
		}

		void warrior_jiaxue_blue(city* blue_quarter_city){ 
			if (red_zhansi && blue_quarter_city->quarter_life>=8){
				blue_quarter_city->quarter_life-=8;
				blue_warrior->life+=8;
				red_zhansi = false;
			}else{
				red_zhansi = false;
			}
		}

//*************************************
		void warrior_jiaxue_chuan_song_gei_jia(city* red_quarter_city, city* blue_quarter_city){ 
			if (life != 0 && red_warrior==NULL && blue_warrior!=NULL){
				timer.zhanshi();
				cout<<"blue "<<blue_warrior->get_name()<<' '<<blue_warrior->get_index()<<" earned "<<life<<" elements for his headquarter"<<endl;
				blue_quarter_city->quarter_life += life;
				life = 0;
			}else if(life != 0 && red_warrior!=NULL && blue_warrior==NULL){
				timer.zhanshi();
				cout<<"red "<<red_warrior->get_name()<<' '<<red_warrior->get_index()<<" earned "<<life<<" elements for his headquarter"<<endl;
				red_quarter_city->quarter_life += life;
				life = 0;
			}
		}


//*************************************

		void warrior_huanhu(){
			if (fa_sheng_zhan_dou){
				if (red_warrior!=NULL && red_warrior->get_name()=="dragon"){
					red_warrior->huanhu("red", index);
				}
				if (blue_warrior!=NULL && blue_warrior->get_name()=="dragon"){
					blue_warrior->huanhu("blue", index);
				}
				fa_sheng_zhan_dou = false;
			}
		}

		void panduan_flag(){
			if (flag=NULL){
				if(red_victory==2){
					timer.zhanshi();
					cout<<"blue flag raised in city"<<index<<endl;
					flag="red";
					red_victory=0;
				}else if(blue_victory==2){
					timer.zhanshi();
					cout<<"red flag raised in city"<<index<<endl;
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
		friend class game;
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
		virtual void lion_escape(){
			if(city::blue_warrior!=NULL && city::blue_warrior -> get_name() == "lion" && city::blue_warrior -> escape()){
				timer.zhanshi();
				cout<<"blue lion "<<city::blue_warrior->warrior::index<<" ran away"<<endl;
				delete city::blue_warrior;
				city::blue_warrior = NULL;
			}
		}

		virtual void warrior_march_1(){
			if (city::shang->red_warrior!=NULL){
				city::red_warrior_tmp = city::shang->red_warrior;
				city::shang->red_warrior=NULL;
			}
		}
		virtual void warrior_march_2(){
			if (city::red_warrior_tmp!=NULL){
				if(city::red_warrior==NULL){// no stop
					city::red_warrior=city::red_warrior_tmp;
					city::red_warrior_tmp = NULL;
					timer.zhanshi();
					cout<<"red "<<city::red_warrior->get_name()<<' '<<city::red_warrior->get_index()<<' '<<"reached blue headquarter with ";
					cout<<city::red_warrior->get_life()<<"elements and force "<<city::red_warrior->get_attack()<<endl;
				}else{//stop
					timer.zhanshi();
					cout<<" red "<<city::red_warrior_tmp->get_name()<<' '<<city::red_warrior_tmp->get_index()<<' '<<"reached blue headquarter with ";
					cout<<city::red_warrior_tmp->get_life()<<"elements and force "<<city::red_warrior_tmp->get_attack()<<endl;
					timer.terminate("blue");
				}
			}
		}

		bool zhizao_dragon(){
			if(quarter_life>=dragon_life){
				float tmp = quarter_life/dragon_life;
				quarter_life -= dragon_life;
				city::blue_warrior = new dragon(Index,dragon_life,dragon_attack,"blue",tmp);
				timer.zhanshi();
				cout<<"blue dragon "<<Index<<" born"<<endl;
				cout<<"Its morale is "<<setprecision(2)<<fixed<<tmp<<endl;
				Index++;
				return true;
			}else{
				return false;
			}
		}
		bool zhizao_ninja(){
			if(quarter_life>=ninja_life){
				quarter_life -= ninja_life;
				city::blue_warrior =new ninja(Index,ninja_life,ninja_attack,"blue");
				timer.zhanshi();
				cout<<"blue ninja "<<Index<<" born"<<endl;
				Index++;
				return true;
			}else{
				return false;
			}
		}
		bool zhizao_iceman(){
			if(quarter_life>=iceman_life){
				quarter_life -= iceman_life;
				city::blue_warrior = new iceman(Index,iceman_life,iceman_attack,"blue");
				timer.zhanshi();
				cout<<"blue iceman "<<Index<<" born"<<endl;
				Index++;
				return true;
			}else{
				return false;
			}
		}
		bool zhizao_lion(){
			if(quarter_life>=lion_life){
				quarter_life -= lion_life;
				city::blue_warrior =new lion(Index,lion_life,lion_attack,"blue",quarter_life);
				timer.zhanshi();
				cout<<"blue lion "<<Index<<" born"<<endl;
				cout<<"Its loyalty is "<<quarter_life<<endl;
				Index++;
				return true;
			}else{
				return false;
			}
		}
		bool zhizao_wolf(){
			if(quarter_life>=wolf_life){
				quarter_life -= wolf_life;
				city::blue_warrior =new wolf(Index,wolf_life,wolf_attack,"blue");
				timer.zhanshi();
				cout<<"blue wolf "<<Index<<" born"<<endl;
				Index++;
				return true;
			}else{
				return false;	
			}
		}
		bool hainengxu(){
			if (quarter_life>=dragon_life||quarter_life>=iceman_life||quarter_life>=ninja_life||quarter_life>=lion_life||quarter_life>=wolf_life){
				return true;		
			}
			else{
				return false;	
			}
		}
		virtual void quarter_baogaoxueliang(){
			timer.zhanshi();
			cout<<quarter_life<<" elements in blue headquarter"<<endl;
		}
		virtual void produce_warrior(){
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
};

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

	int Index=0;

	public:
		friend class game;
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

		virtual void lion_escape(){
			if(city::red_warrior -> get_name() == "lion" && city::red_warrior -> escape()){
				timer.zhanshi();
				cout<<"red lion "<<city::red_warrior->warrior::index<<" ran away"<<endl;
				delete city::red_warrior;
				city::red_warrior = NULL;
			}
		}

		virtual void warrior_march_1(){
			if (city::xia->blue_warrior!=NULL){
				city::blue_warrior_tmp = city::xia->blue_warrior;
				city::xia->blue_warrior=NULL;
			}
		}
		virtual void warrior_march_2(){
			if (city::blue_warrior_tmp!=NULL){
				if(city::blue_warrior==NULL){// no stop
					city::blue_warrior=city::blue_warrior_tmp;
					city::blue_warrior_tmp = NULL;
					timer.zhanshi();
					cout<<"blue "<<city::blue_warrior->get_name()<<' '<<city::blue_warrior->get_index()<<' '<<"reached red headquarter with ";
					cout<<city::blue_warrior->get_life()<<"elements and force "<<city::blue_warrior->get_attack()<<endl;
				}else{//stop
					timer.zhanshi();
					cout<<" blue "<<city::blue_warrior_tmp->get_name()<<' '<<city::blue_warrior_tmp->get_index()<<' '<<"reached red headquarter with ";
					cout<<city::blue_warrior_tmp->get_life()<<"elements and force "<<city::blue_warrior_tmp->get_attack()<<endl;
					timer.terminate("red");
				}
			}
		}
		bool zhizao_dragon(){
			if(quarter_life>=dragon_life){
				float tmp = quarter_life/dragon_life;
				quarter_life -= dragon_life;
				city::red_warrior = new dragon(Index,dragon_life,dragon_attack,"red",tmp);
				timer.zhanshi();
				cout<<"red dragon "<<Index<<" born"<<endl;
				cout<<"Its morale is "<<setprecision(2)<<fixed<<tmp<<endl;
				Index++;
				return true;
			}else{
				return false;
			}
		}
		bool zhizao_ninja(){
			if(quarter_life>=ninja_life){
				quarter_life -= ninja_life;
				city::red_warrior = new ninja(Index,ninja_life,ninja_attack,"red");
				timer.zhanshi();
				cout<<"red ninja "<<Index<<" born"<<endl;
				Index++;
				return true;
			}else{
				return false;
			}
		}
		bool zhizao_iceman(){
			if(quarter_life>=iceman_life){
				quarter_life -= iceman_life;
				city::red_warrior =new iceman(Index,iceman_life,iceman_attack,"red");
				timer.zhanshi();
				cout<<"red iceman "<<Index<<" born"<<endl;
				Index++;
				return true;
			}else{
				return false;
			}
		}
		bool zhizao_lion(){
			if(quarter_life>=lion_life){
				quarter_life -= lion_life;
				city::red_warrior =new lion(Index,lion_life,lion_attack,"red",quarter_life);
				timer.zhanshi();
				cout<<"red lion "<<Index<<" born"<<endl;
				cout<<"Its loyalty is "<<quarter_life<<endl;
				Index++;
				return true;
			}else{
				return false;
			}
		}
		bool zhizao_wolf(){
			if (quarter_life>=wolf_life){
				quarter_life -= wolf_life;
				city::red_warrior =new wolf(Index,wolf_life,wolf_attack,"red");
				timer.zhanshi();
				cout<<"red wolf "<<Index<<" born"<<endl;
				Index++;
				return true;
			}else{
				return false;
			}
		}
		bool hainengxu(){
			if (quarter_life>=dragon_life||quarter_life>=iceman_life||quarter_life>=ninja_life||quarter_life>=lion_life||quarter_life>=wolf_life){
				return true;		
			}
			else{
				return false;	
			}
		}
		virtual void quarter_baogaoxueliang(){
			timer.zhanshi();
			cout<<quarter_life<<" elements in red headquarter"<<endl;
		}
		virtual void produce_warrior(){
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
};

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
					citys[ii] = new red_quarter(ii,M,dragon_life,dragon_attack,ninja_life,ninja_attack,iceman_life,iceman_attack,lion_life,lion_attack,wolf_life,wolf_attack);
				}
				else if (ii==N+1){
					citys[ii] = new blue_quarter(ii,M,dragon_life,dragon_attack,ninja_life,ninja_attack,iceman_life,iceman_attack,lion_life,lion_attack,wolf_life,wolf_attack);
				}
				else{
					citys[ii] = new city(ii);
				}
			}
			for (int ii=0;ii<(N+2);ii++){
				if (ii==0){
					citys[ii]->city::xia = citys[ii+1];
					citys[ii]->city::red_quarter_city = citys[0];
					citys[ii]->city::blue_quarter_city = citys[N+1];
				}
				else if (ii==N+1){
					citys[ii]->city::shang = citys[ii-1];
					citys[ii]->city::red_quarter_city = citys[0];
					citys[ii]->city::blue_quarter_city = citys[N+1];
				}
				else{
					citys[ii]->shang = citys[ii-1];
					citys[ii]->xia = citys[ii+1];
					citys[ii]->city::red_quarter_city = citys[0];
					citys[ii]->city::blue_quarter_city = citys[N+1];
				}
			}
		}
		~game(){
			for(int i=0;i<counter_city;i++){
				delete citys[i];
				citys[i]=NULL;
			}
			delete[] citys;
		}
		void birth(){
			citys[0]->produce_warrior();
			citys[counter_city-1]->produce_warrior(); 
		} //
		void escape(){
			for (int i=0;i<counter_city;i++){
				citys[i]->lion_escape();
			}
		} //
		void march(){
			for (int i=0;i<counter_city;i++){
				citys[i]->warrior_march_1();
			}
			for (int i=0;i<counter_city;i++){
				citys[i]->warrior_march_2();
			}
		} //
		void fangjian(){
			for (int i=0;i<counter_city;i++){
				citys[i]->arrow_shot();
			}
		} //
		void game_qingzhen(){
			for (int i=1;i<counter_city-1;i++){
				citys[i]->warrior_qingzhen();
			}
		} //
		void battle(){
			for (int i=1;i<counter_city-1;i++){
				citys[i]->warrior_attack();
			}
		}  //
		void fanji(){
			for (int i=1;i<counter_city-1;i++){
				citys[i]->warrior_fanji();
			}
		} //
		void jiaxue(){
			for (int i=1;i<counter_city-1;i++){
				citys[i]->warrior_jiaxue_chuan_song_gei_jia(citys[0],citys[counter_city-1]);
			}
		} //
		void huanhu(){
			for (int i=1;i<counter_city-1;i++){
				citys[i]->warrior_huanhu();
			}
		}

		void shengqi(){
			for (int i=1;i<counter_city-1;i++){
				citys[i]->panduan_flag();
			}
		} //
		void baogaoxueliang(){
			citys[0]->quarter_baogaoxueliang();
			citys[counter_city-1]->quarter_baogaoxueliang();
		} //
		void baogaowuqi(){
			for (int i=0;i<counter_city;i++){
				citys[i]->city_baogaowuqi_red();
			}
			for (int i=0;i<counter_city;i++){
				citys[counter_city-1-i]->city_baogaowuqi_blue();
			}
		} //
		void killed(){
			for (int i=1;i<counter_city-1;i++){
				citys[i]->warrior_zhansi();
			}
		}
		void gei_warrior_jiaxue(){
			for (int i=1;i<counter_city-1;i++){
				citys[i]->warrior_jiaxue_red(citys[0]);
				citys[counter_city-1-i]->warrior_jiaxue_blue(citys[counter_city-1]);
			}
		}
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
				if (timer.fen==10){ // 这里的逻辑问题可能还没有解决，我回头再来解决这个
					march();
				}
				if (timer.fen==20){
					for (int i=1;i<counter_city-1;i++){
						citys[i]->life+=10;
					}
				}
				if (timer.fen==30){
					jiaxue();
				}
				if (timer.fen==35){
					fangjian();
				}
				if (timer.fen==38){
					game_qingzhen();
				}
				if (timer.fen==40){
					battle();
					fanji();
					killed();
					gei_warrior_jiaxue();
					huanhu();
					jiaxue();
					shengqi();
				}
				if (timer.fen==50){
					baogaoxueliang();
				}
				if (timer.fen==55){
					baogaowuqi();
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
		game newgame(M,N,dragon_life,ninja_life,iceman_life,lion_life,wolf_life,dragon_attack,ninja_attack,iceman_attack,lion_attack,wolf_attack);
		timer.reset();
		newgame.start();
	}
	return 0;
	}









