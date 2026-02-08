#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

int to_d(int x)
{
    int i = 0;
    while (x)
    {
        i++;
        x /= 10;
    }
    return i;
}

void solve()
{
    int n;
    priority_queue<int> pq_a, pq_b;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pq_a.push(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pq_b.push(x);
    }
    int res = 0;

    while (pq_a.size())
    {
        int a = pq_a.top(), b = pq_b.top();

        if (a == b)
        {
            pq_a.pop();
            pq_b.pop();
        }
        else if (a > b)
        {
            res++;
            pq_a.pop();
            pq_a.push(to_d(a));
        }
        else
        {
            res++;
            pq_b.pop();
            pq_b.push(to_d(b));
        }
    }

    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}