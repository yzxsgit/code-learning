#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, M = 210;

struct Edges{
    int a, b, w;
    bool operator<(const Edges &t) const {
        return w < t.w;
    }
} e[M];
int p[N];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int n, m;

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
        int a = find(e[i].a), b = find(e[i].b);
        if (a != b)
            p[a] = b;
        else
            res += e[i].w;
    }

    cout << res << "\n";

    return 0;
}