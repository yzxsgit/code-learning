#include <iostream>

using namespace std;
const int N = 510, M = 6e3 + 10;
int n, m;
int f[M];
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int v, w, s;
        cin >> v >> w >> s;
        for (int j = m; j >= 0; j--)
            for (int k = 0; k <= min(s, j / v); k++)
                f[j] = max(f[j], f[j - k * v] + k * w);
    }

    cout << f[m] << '\n';

    return 0;
}