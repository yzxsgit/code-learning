#include <iostream>
#include <cstring>

using namespace std;

const int N = 6010;
int happy[N];
int h[N], e[N], ne[N], idx;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int n;
int f[N][2];
bool has_father[N];
void dfs(int x)
{
    f[x][1] = happy[x];

    for (int i = h[x]; ~i; i = ne[i])
    {
        int j = e[i];

        dfs(j);

        f[x][0] += max(f[j][1], f[j][0]);
        f[x][1] += f[j][0];
    }
}
int main()
{
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> happy[i];
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        add(b, a);
        has_father[a] = true;
    }

    int root = 1;
    while (has_father[root])
        root++;

    dfs(root);

    cout << max(f[root][0], f[root][1]);

    return 0;
}