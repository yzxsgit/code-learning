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

void solve()
{
    int n;
    cin >> n;
    int a;
    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        mp[a]++;
    }

    for (auto [a, cnt] : mp)
        if (cnt >= 4)
        {
            cout << "Yes\n";
            return;
        }

    bool flag = false, bg = false;
    PII last;
    for (auto [a, cnt] : mp)
    {
        if (!bg)
        {
            last.first = a;
            last.second = cnt;
            if (cnt >= 2)
                flag = true;
            bg = true;
        }
        else
        {
            if (flag)
            {
                if (a == last.first + 1 && cnt >= 2)
                {
                    cout << "Yes\n";
                    return;
                }
                else if (a == last.first + 2 && last.second >= 3)
                {
                }
                else if (a == last.first + 1)
                {
                }
                else
                {
                    flag = false;
                }
            }
            else
            {
                if (cnt >= 2)
                {
                    flag = true;
                }
            }
        }
        last = {a, cnt};
    }

    cout << "No\n";
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