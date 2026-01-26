#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 310, M = 8010;

struct Edges{
    int a, b, w;

    bool operator<(const Edges &t)
    {
        return w < t.w;
    }
} e[M];

int p[N];
int n, m;

int find(int x)
{
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        p[i] = i;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        e[i] = {a, b, c};
    }

    sort(e, e + m);

    int res = 0;
    for (int i = 0; i < m; i++)
    {
        int a = find(e[i].a), b = find(e[i].b), w = e[i].w;
        if (a != b)
        {
            p[a] = b;
            res = w;
        }
    }

    cout << n - 1 << " " << res << "\n";

    return 0;
}