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

map<int, string> res;
int n;

void bfs()
{
    queue<int> q;
    q.push(1);
    res[1] = "1";

    while (q.size())
    {
        int t = q.front();
        q.pop();

        if (t == 0)
            return;
        string s = res[t];

        int left = t * 10 % n;
        if (!res.count(left))
        {
            q.push(left);
            res[left] = s + "0";
        }
        left++;
        left = left % n;

        if (!res.count(left))
        {
            q.push(left);
            res[left] = s + "1";
        }
    }

    return;
}

void solve()
{
    res.clear();

    bfs();

    cout << res[0] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n && n)
    {
        solve();
    }
    return 0;
}