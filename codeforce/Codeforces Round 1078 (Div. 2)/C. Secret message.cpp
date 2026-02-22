#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

void solve()
{
    int n, k;
    cin >> n >> k;
    string str[k];
    for (int i = 0; i < k; i++)
        cin >> str[i];

    vector<int> factors;
    factors.push_back(1);
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
            factors.push_back(i);
    }
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            a[i] |= 1 << (str[j][i] - 'a');
        }
        // cout << a[i] << '\n';
    }
    for (auto d : factors)
    {
        bool flag = true;
        string ans = "";
        for (int i = 0; i < d; i++)
        {
            int tmp = a[i];
            for (int j = 1; j < n / d; j++)
            {
                tmp &= a[i + d * j];
            }
            if (!tmp)
            {
                flag = false;
                break;
            }
            int l = 0;
            while ( ((tmp >> l) & 1) == 0)
                l++;
            ans = ans + char('a' + l);
        }
        if (flag)
        {
            for (int i = 0; i < n / d; i++)
                cout << ans;
            cout << '\n';
            return;
        }
    } 
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