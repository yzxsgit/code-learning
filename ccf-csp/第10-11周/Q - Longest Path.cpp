#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
int indegree[N];
int f[N];
void add(int a,int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int n, m;
int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
        indegree[y]++;
    }

    queue<int> q;
    for (int i = 1; i <= n;i++)
        if(indegree[i] == 0)
            q.push(i);

    int ans = 0;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        ans = max(ans, f[t]);

        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            f[j] = max(f[j], f[t] + 1);
            indegree[j]--;
            if(!indegree[j])
                q.push(j);
        }
    }

    cout << ans << endl;

    return 0;
}