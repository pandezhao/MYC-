#include <iostream>
using namespace std;

int main()
{
    int sample[100][100];
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> sample[i][j];
        }
    }
    int cellX = 0;
    for (int i = 1; i < N-1; i++)
    {
        for (int j = 1; j < N-1; j++)
        {
            if (sample[i][j] <= sample[i-1][j]-50 && sample[i][j] <= sample[i+1][j]-50 &&\
                sample[i][j] <= sample[i][j-1]-50 &&sample[i][j] <= sample[i][j+1]-50)
            {
                cellX++;
            } 
        }
    }
    cout << cellX << endl;
    return 0;
}
