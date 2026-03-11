#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

int find(vector<int> &p, int x)
{
    if (p[x] != x)
        p[x] = find(p, p[x]);
    return p[x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> p(n + 1);
    for (int i = 1; i <= n;i++)
    {
        p[i] = i;
    }

    auto check = [&](int a, int b)
    { 
        return find(p, a) == find(p, b); 
    };
    auto merge = [&](int a, int b)
    {
        a = find(p, a), b = find(p, b);
        if (a != b)
            p[a] = b;
    };

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << (check(a, b) ? "Yes\n" : "No\n");
    }

    return 0;
}