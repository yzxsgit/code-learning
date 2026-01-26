#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e3 + 10, M = 1e4 + 10;

struct Edges{
    int a, b, w;
    bool operator< (const Edges &t)
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

    int idx = 0;
    int res = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c, d;
        cin >> d >> a >> b >> c;
        a = find(a), b = find(b);
        if(d == 1)
        {
            res += c;
            p[a] = find(b);
        }
        else 
        {
            e[idx++] = {a, b, c};
        }
    }

    sort(e, e + idx);

    for (int i = 0; i < idx; i++)
    {
        int a = find(e[i].a), b = find(e[i].b), w = e[i].w;

        if( a != b)
        {
            p[a] = b;
            res += w;
        }
    }

    cout << res << "\n";

    return 0;
}