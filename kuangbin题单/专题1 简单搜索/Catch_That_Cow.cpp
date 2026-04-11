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

const int N = 1e5 + 10;

bool st[N];

int bfs(int n, int k)
{
    queue<PII> q;

    q.push({0, n});

    st[n] = true;

    while (q.size())
    {
        PII t = q.front();
        q.pop();

        int d = t.first;
        int u = t.second;
        if (u == k)
            return d;

        if (u + 1 < N && !st[u + 1])
        {
            q.push({d + 1, u + 1});
            st[u + 1] = true;
        }
        if (u - 1 >= 0 && !st[u - 1])
        {
            q.push({d + 1, u - 1});
            st[u - 1] = true;
        }
        if (u * 2 < N && !st[u * 2])
        {
            q.push({d + 1, u * 2});
            st[u * 1] = true;
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;

    cin >> n >> k;

    cout << bfs(n, k) << '\n';

    return 0;
}