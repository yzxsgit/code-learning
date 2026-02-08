#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    i64 res = 0, now = 0;
    for (int i = 0; i < n; i++)
    {
        i64 minn = 1e18;
        int sel = -1;
        for (auto [key , num] : mp)
        {
            if (num == 0)
                continue;
            i64 tmp = now + key - now % key;
            if (minn > tmp || sel == -1)
            {
                minn = tmp;
                sel = key;
            }
        }
        mp[sel]--;
        res += minn;
        now = minn;
    }

    cout << res << '\n';

    return 0;
}