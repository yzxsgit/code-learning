#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <iomanip>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 1e4 + 10;

struct Segment
{
    double x, y1, y2;
    int k;
};

bool cmp(Segment a, Segment b)
{
    return a.x < b.x;
}

struct Node
{
    int l, r;
    int cnt;
    double len;
} tr[N * 8];

vector<double> ys;
int n;

int find(double y)
{
    return lower_bound(ys.begin(), ys.end(), y) - ys.begin();
}

void pushup(int u)
{
    if (tr[u].cnt)
    {
        tr[u].len = ys[tr[u].r + 1] - ys[tr[u].l];
    }
    else if (tr[u].l != tr[u].r)
    {
        tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
    }
    else 
    {
        tr[u].len = 0;
    }
}

void build(int u, int l, int r)
{
    tr[u] = {l, r, 0, 0};
    if (l != r)
    {
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }
}

void modify(int u,int l, int r, int k)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].cnt += k;
        pushup(u);
    }
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid)
            modify(u << 1, l, r, k);
        if (r > mid)
            modify(u << 1 | 1, l, r, k);
        pushup(u);
    }
}

void solve(int T)
{
    ys.clear();
    vector<Segment> Seg;
    for (int i = 0; i < n; i++)
    {
        double x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Seg.push_back({x1, y1, y2, 1});
        Seg.push_back({x2, y1, y2, -1});
        ys.push_back(y1),ys.push_back(y2);
    }

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    build(1, 0, ys.size() - 2);

    sort(Seg.begin(), Seg.end(), cmp);

    double res = 0;
    for (int i = 0; i < n * 2; i++)
    {
        if (i > 0)
            res += tr[1].len * (Seg[i].x - Seg[i - 1].x);
        modify(1, find(Seg[i].y1), find(Seg[i].y2) - 1, Seg[i].k);
    }
    cout << "Test case #" << T << '\n';
    cout << "Total explored area: " << fixed << setprecision(2) << res << '\n' << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T = 1;
    while (cin >> n && n)
    {
        solve(T);
        T++;
    }
    return 0;
}