#include <iostream>

using namespace std;
const int M = 1e3 + 10;
int f[M];
int n, m;

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int v, w, s;
        cin >> v >> w >> s;
        if(s == 0)
            for (int j = v; j <= m; j++)
                f[j] = max(f[j], f[j - v] + w);
        else
        {
            if (s == -1)
                s = 1;
            for (int k = 1; k <= s; k *= 2)
            {
                for (int j = m; j >= v * k; j--)
                    f[j] = max(f[j], f[j - k * v] + k * w);
                s -= k;
            }
            if(s)
            {
                for (int j = m; j >= s * v; j--)
                    f[j] = max(f[j], f[j - v * s] + s * w);
            }
        }
    }

    cout << f[m] << "\n";

    return 0;
}