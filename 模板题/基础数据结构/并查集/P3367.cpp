#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <functional>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> p(n + 1);

    for (int i = 1; i <= n; i++)
        p[i] = i;

    function<int(int)> find = [&](int x)
    {
        if (x != p[x])
            p[x] = find(p[x]);
        return p[x];
    };

    auto check = [&](int a, int b)
    {
        a = find(a), b = find(b);
        return a == b;
    };

    auto merge = [&](int a, int b)
    {
        a = find(a), b = find(b);
        if (a != b)
            p[a] = b;
    };

    while (m--)
    {
        int op, a, b;
        cin >> op >> a >> b;

        if (op == 1)
        {
            merge(a, b);
        }
        else
        {
            cout << (check(a, b) ? 'Y' : 'N') << endl;
        }
    }

    return 0;
}