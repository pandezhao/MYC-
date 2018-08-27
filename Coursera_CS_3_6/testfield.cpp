#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
using namespace std;
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

int main(){
	int i=3;
	weapon* tmp;
	tmp = new sword(4);
}
