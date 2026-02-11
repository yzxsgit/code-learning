#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 4e4 + 10, Base = 1e4;

int n, m;
int p[N];
int idx = 0;
unordered_map<int, int> S;

int get(int x)
{
    if (!S.count(x)) S[x] = ++idx;
    return S[x];
}

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < N; i++)
        p[i] = i;

    int res = m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        string op;
        cin >> a >> b >> op;
        a = get(a - 1), b = get(b);
        if (op == "even")
        {
            if (find(a + Base) == find(b))
            {
                res = i - 1;
                break;
            }

            p[find(a)] = find(b);
            p[find(a + Base)] = find(b + Base);
        }
        else
        {
            if (find(a) == find(b))
            {
                res = i - 1;
                break;
            }

            p[find(a + Base)] = find(b);
            p[find(a)] = find(b + Base);
        }
    }

    cout << res << '\n';

    return 0;
}