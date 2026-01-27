#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

const int N = 510, M = N * N / 2;
typedef pair<int, int> PII;

struct Edges
{
    int a, b;
    double w;
    bool operator<(const Edges &t) const 
    {
        return w < t.w;
    }
} e[M];

int n, k, m;
PII q[M];

double get_dist(PII a,PII b)
{
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

int p[N];
int find(int x)
{
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        p[i] = i;
    for (int i = 0; i < n; i++)
        cin >> q[i].first >> q[i].second;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            e[m++] = {i, j, get_dist(q[i], q[j])};

    sort(e, e + m);

    int cnt = n;
    double res = 0;
    for (int i = 0; i < m; i++)
    {
        if (cnt <= k)
            break;
        int a = find(e[i].a), b = find(e[i].b);
        double w = e[i].w;
        if (a != b)
        {
            cnt--;
            res = w;
            p[a] = b;
        }
    }

    cout << fixed << setprecision(2) << res << "\n";

    return 0;
}