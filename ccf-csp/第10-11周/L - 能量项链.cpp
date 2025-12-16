#include <iostream>

using namespace std;
const int N = 210;
int n;
int f[N][N];
int e[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> e[i];
        e[i + n] = e[i];
    }
    e[0] = e[n];
    for (int j = 1; j < 2 * n; j++)
        for (int i = j; i >= 1 && i > j - n;i--)
        {
            for (int k = i; k < j; k++)
                f[i][j] = max(f[i][k] + f[k + 1][j] + e[i] * e[k + 1] * e[j + 1], f[i][j]);
        }
    int E = 0;
    for (int i = 1; i <= n; i++)
        E = max(E, f[i][i + n - 1]);
    cout << E << endl;
   
    return 0;

}