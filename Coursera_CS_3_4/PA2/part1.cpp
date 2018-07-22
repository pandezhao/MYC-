#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
    void operator=(string a){
		int first_p = a.find("+", 0);
		int second_p = a.find("i", 0);
		double real = atof(a.substr(0, first_p).c_str());
		double img = atof(a.substr(first_p+1, second_p).c_str());
		this->r = real;
		this->i = img;
    }
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
