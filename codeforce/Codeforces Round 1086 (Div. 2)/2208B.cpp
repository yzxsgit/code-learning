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
using namespace std;

void solve()
{
    int n, k, p, m;
    cin >> n >> k >> p >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    if (k == n)
    {
        cout << m / a[p] << '\n';
        return;
    }

    queue<int> q;                                      
    priority_queue<int, vector<int>, greater<int>> pq; 

    bool flag = false; 

    if (p <= k)
        flag = true;
    for (int i = 1; i <= k; i++)
    {
        if (i != p)
            pq.push(a[i]);
    }

    for (int i = k + 1; i <= n; i++)
    {
        if (i == p)
            q.push(-1); 
        else
            q.push(a[i]);
    }

    int res = 0; 
    while (m > 0)
    {
        if (flag)
        {
            if (m >= a[p])
            {
                m -= a[p];
                res++;

                q.push(-1);   
                flag = false; 

                int nxt = q.front();
                q.pop();
                if (nxt == -1)
                    flag = true;
                else
                    pq.push(nxt);
            }
            else
            {
                break;
            }
        }
        else
        {
            if (pq.empty())
                break;

            int tmp = pq.top();
            if (m >= tmp)
            {
                m -= tmp;
                pq.pop();

                q.push(tmp); 

                int nxt = q.front();
                q.pop();
                if (nxt == -1)
                    flag = true;
                else
                    pq.push(nxt);
            }
            else
            {
                break; 
            }
        }
    }

    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (cin >> T)
    {
        while (T--)
        {
            solve();
        }
    }
    return 0;
}