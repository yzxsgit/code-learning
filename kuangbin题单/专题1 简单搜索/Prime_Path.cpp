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
using PII = pair<int, int>;

const int N = 10000;

int p[N];
vector<bool> prime(N, true);

void init()
{
    int cnt = 0;
    prime[0] = prime[1] = false;

    for (int i = 2; i < N; i++)
    {
        if (prime[i])
            p[cnt++] = i;
        for (int j = 0; j < cnt && i * p[j] < N; j++)
        {
            prime[i * p[j]] = false;
            if (i % p[j] == 0)
                break;
        }
    }
}

int bfs(int bg, int ed)
{
    const int h[] = {1, 10, 100, 1000};

    queue<PII> q;
    vector<bool> st(N, false);

    q.push({0, bg});
    st[bg] = true;

    while (q.size())
    {
        PII t = q.front();
        q.pop();

        int d = t.first;
        int u = t.second;

        if (u == ed)
            return d;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (i == 3 && j == 0)
                    continue;
                int v = u + h[i] * (j - (u / h[i] % 10));

                if (!st[v] && prime[v])
                {
                    q.push({d + 1, v});
                    st[v] = true;
                }
            }
        }
    }

    return -1;
}

void solve()
{
    int st, ed;

    cin >> st >> ed;

    int res = bfs(st, ed);

    if (res == -1)
    {
        cout << "Impossible\n";
    }
    else
    {
        cout << res << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}