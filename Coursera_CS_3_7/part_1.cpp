#include <iostream>
using namespace std;

template <class T1>
class CArray3D{
    public:
    template <class T2>
    class CArray2D{
        public:
            template <class T3>
            class CArray1D{
                public:
                    CArray1D(){
                        data = NULL;
                    }
                    void set(int z){
                        data = new T3[z];
                    }
                    T3& operator[](int tmp){
                        return data[tmp];
                    }
                    ~CArray1D(){delete []data;}
                private:
                    T3* data;
            };
            CArray2D(){
                data = NULL;
            }
            void set(int y,int z){
                data = new CArray1D<T2> [y];
                for (int i=0;i<y;i++){
                    data[i].set(z);
                }
            }
            CArray1D<T2>& operator[](int tmp){
                return data[tmp];
            }
            ~CArray2D(){
                delete [] data;
            }
        private:
            CArray1D<T2>* data;
    };
    CArray3D(int x,int y,int z){
        data = new CArray2D<T1>[x];
        for (int i=0;i<x;i++){
            data[i].set(y,z);
        }
    }
    CArray2D<T1>& operator[](int tmp){
        return data[tmp];
    }
    ~CArray3D(){
        delete [] data;
    }
    private:
        CArray2D<T1>* data;
};

int main()
{
    CArray3D<int> a(3,4,5);
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << a[i][j][k] << ",";
    // cout<<"begin"<<endl;
    // CArray2D test(3,3);
    // int t=0;
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         test[i][j]=t;
    //         t++;
    //     }
    // }
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         cout<<test[i][j]<<endl;
    //     }
    // }
    return 0;
}