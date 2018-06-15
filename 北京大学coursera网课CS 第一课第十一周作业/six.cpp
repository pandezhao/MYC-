#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> samle(n);
    for (int i = 0; i < n; i++)
    {
        cin >> samle[i];
    }

    for (int i = 0; i < m; i++)
    {
        int temp = samle[n-1];
        for (int j = 0; j < n-1; j++)
        {
            samle[n-1-j] = samle[n-j-2];
        }
        samle[0] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        if (i != n-1)
        {
            cout << samle[i] << " ";
        }
        else
        {
            cout << samle[i] << endl;
        }
    }
    return 0;
}
