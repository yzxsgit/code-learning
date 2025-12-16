#include <iostream>

using namespace std;
const int N = 1e4 + 10;
int f[N];
int n, m;

int main()
{
    
    cin >> n >> m;

    f[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        for (int j = m; j >= a; j--)
            f[j] += f[j - a];
    }

    cout << f[m] << endl;

    return 0;
}