#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using PII = pair<int, int>;

const int N = 2e5 + 10;

int p[N];

int find(int x)
{
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}

struct Edge
{
    int a, b, w, e;
};

bool cmp1(Edge x, Edge y)
{
    return x.w < y.w;
}

void solve()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w, i + 1};
    }
    sort(edges.begin(), edges.end(), cmp1);

    for (int i = 1; i <= n; i++)
        p[i] = i;

    vector<Edge> mst;
    for (int i = 0; i < m; i++)
    {
        int a = find(edges[i].a), b = find(edges[i].b);
        if (a != b)
        {
            p[a] = b;
            mst.push_back(edges[i]);
        }
    }

    int drop_cnt = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (drop_cnt < k && mst[i].w > 1)
        {
            drop_cnt++;
            mst[i].w = -1; 
        }
    }

    for (int i = 1; i <= n; i++)
        p[i] = i;

    i64 res = 0;
    vector<Edge> ans;
    for (int i = 0; i < n - 1; i++)
    {
        if (mst[i].w != -1)
        {
            int a = find(mst[i].a), b = find(mst[i].b);
            p[a] = b;
            res += mst[i].w;
            ans.push_back(mst[i]);
        }
    }

    int add = 0;
    vector<PII> add_PII;
    for (int i = 1; i < n; i++)
    {
        int a = find(i), b = find(i + 1);
        if (a != b)
        {
            p[a] = b;
            add++;
            add_PII.push_back({i, i + 1});
            res += 1;
            ans.push_back({i, i + 1, 1, add + m});
        }
    }

    printf("%d\n", add);
    for (auto [u, v] : add_PII)
        printf("%d %d\n", u, v);
    printf("%lld\n", res);

    for (int i = 0; i < n - 1; i++)
        printf("%d ", ans[i].e);
    printf("\n");
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}