#include <iostream>
#include <cstring>

using namespace std;
const int N = 1510;

int e[N], h[N], ne[N], idx;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int n;
int f[N][3], w[N];
bool st[N];

void dfs(int u)
{
    f[u][1] = w[u];

    int sum = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];

        dfs(j);

        f[u][0] += min(f[j][1], f[j][2]);
        f[u][1] += min(f[j][1], min(f[j][0], f[j][2]));
        sum += min(f[j][1], f[j][2]);
    }

    f[u][2] = 1e9;

    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        f[u][2] = min(f[u][2], sum - min(f[j][1], f[j][2]) + f[j][1]);
    }
}

int main()
{
    memset(h, -1, sizeof h);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int ver, value, id, m;
        cin >> id >> value >> m;
        w[id] = value;
        
        while (m--)
        {
            cin >> ver;
            add(id, ver);
            st[ver] = true;
        }
    }

    int root = 1;
    while (st[root])
        root++;

    dfs(root);

    cout << min(f[root][1], f[root][2]) << endl;

    return 0;
}