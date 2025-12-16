#include <iostream>
#include <vector>
using namespace std;
const int M = 4e4 + 10, N = 70;
struct item{
    int v, w;
}master[N];
vector<item> servent[N];

int f[M];

int main()
{
    int n, m;
    cin >> m >> n;

    for (int i = 1; i <= n; i++)
    {
        int v, w, q;
        cin >> v >> w >> q;
        if(!q)
            master[i] = {v, v * w};
        else
            servent[q].push_back({v, v * w});
    }

    for (int i = 1; i <= n; i++)
    {
        for (int u = m; u >= 0; u--)
        {
            for (int j = 0; j < 1 << servent[i].size(); j++)
            {
                int v = master[i].v, w = master[i].w;
                for (int k = 0; k < servent[i].size(); k++)
                {
                    if (j >> k & 1)
                    {
                        auto &st = servent[i];
                        v += st[k].v;
                        w += st[k].w;
                    }
                }
                if(u >= v)
                    f[u] = max(f[u], f[u - v] + w);
            }
        }
    }

    cout << f[m] << "\n";

    return 0;
}