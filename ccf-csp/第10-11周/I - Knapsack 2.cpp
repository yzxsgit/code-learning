#include <iostream>
#include <cstring>
using namespace std;
const int N = 110, M = 1010;
int f[M*N];
int v[N], w[N];

int n, m;
int main()
{
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    int max_v = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
        max_v += v[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = max_v; j >= v[i]; j--)
            if(f[j - v[i]]!=0x3f3f3f3f)
                f[j] = min(f[j - v[i]] + w[i], f[j]);
    }

    for (int i = max_v; i >= 0; i--)
        if(f[i] <= m)
        {
            cout << i << endl;
            break;
        }

    return 0;
}