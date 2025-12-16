#include <iostream>

using namespace std;

const int M = 3e4 + 10, N = 30;
int n, m;
int f[M];

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= v; j--)
            f[j] = max(f[j], f[j - v] + v * w);
    }

    cout << f[m] << "\n";

    return 0;
}