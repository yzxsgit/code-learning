#include <iostream>
#include <algorithm>

using namespace std;

const int N = 6e3 + 10;

struct Edge
{
    int a, b, w;
    bool operator<(const Edge &t) const 
    {
        return w < t.w;
    }
} e[N];

int p[N], s[N];
int n;

int find(int x)
{
    if (x != p[x])
        p[x] = find(p[x]);

    return p[x];
}

void solve()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        s[i] = 1;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        e[i] = {a, b, c};
    }

    sort(e, e + n - 1);

    int res = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int a = find(e[i].a),b = find(e[i].b),w = e[i].w;
        if (a != b)
        {
            res += (s[a] * s[b] - 1) * (w + 1);
            s[b] += s[a];
            p[a] = b;
        }
    }

    cout << res << "\n";
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        solve();
    }

    return 0;
}