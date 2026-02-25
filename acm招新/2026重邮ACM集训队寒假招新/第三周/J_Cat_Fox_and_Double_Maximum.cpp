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
    vector<int> p(n);

    for (int i = 0; i < n; i++)
        cin >> p[i];

    int res = -1;
    vector<int> res_q;
    for (int k = 0; k < 2; k++)
    {
        vector<int> tmp_q(n);
        vector<PII> peak, valley;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && i < n - 1 && i % 2 == k)
            {
                peak.push_back({p[i], i});
            }
            else 
            {
                valley.push_back({p[i], i});
            }
        }
        sort(peak.begin(), peak.end());
        sort(valley.begin(), valley.end());

        int j = n;
        for (auto [val, id] : peak)
            tmp_q[id] = j--;
        for (auto [val, id] : valley)
            tmp_q[id] = j--;

        int score = 0;
        for (int i = 1; i < n - 1;i++)
        {
            int a1 = tmp_q[i - 1] + p[i - 1];
            int a2 = tmp_q[i] + p[i];
            int a3 = tmp_q[i + 1] + p[i + 1];
            if (a1 < a2 &&a3 < a2)
            {
                score++;
            }
        }

        if (score > res)
        {
            res = score;
            res_q = tmp_q;
        }
    }

    for (auto ans : res_q)
    {
        cout << ans << ' ';
    }

    cout << '\n';
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