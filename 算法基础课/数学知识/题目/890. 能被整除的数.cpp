#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int p[N];
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> p[i];

    int res = 0;
    for (int i = 1; i < 1 << m; i++)
    {
        int t = 1, sum = 0;
        for (int j = 0; j < m;j++)
            if (i >> j & 1)
            {
                if ((long long)p[j] * t > n)
                {
                    t = -1;
                    break;
                }
                sum++;
                t *= p[j];
            }
        if(t != -1)
        {
            if(sum & 1)
                res += n / t;
            else
                res -= n / t;
        }
    }

    cout << res << endl;

    return 0;
}