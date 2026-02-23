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

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> b(n + 2, n + 1);
    int tmp = n + 1;
    for (int i = n; i >= 1; i--)
    {
        if (i < n && a[i + 1] - a[i] >= 2)
        {
            tmp = i + 1;
        }
        b[i] = tmp;
    }

    vector<int> c(n + 2, n + 1);
    stack<int> st;
    for (int i = n; i >= 1; i--)
    {
        while (!st.empty() && a[st.top()] > a[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            c[i] = st.top();
        }
        st.push(i);
    }

    i64 ans = 0;
    vector<i64> f(n + 2, 0); 
    
    for (int i = n; i >= 1; i--)
    {
        int nxt = min(b[i], c[i]);
        f[i] = (n - i + 1) + f[nxt];
        ans += f[i];
    }

    cout << ans << '\n';
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