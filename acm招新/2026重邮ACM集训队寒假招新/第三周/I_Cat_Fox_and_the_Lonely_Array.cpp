#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <bitset>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;

void solve()
{
    int n;
    cin >> n;

    vector<int> last(20, 0);
    vector<int> gap(20, 0);
    bitset<20> has;

    for (int i = 1; i <= n; i++)
    {
        int val;
        cin >> val;
        bitset<20> b(val);

        for (int j = 0; j < 20; j++)
        {
            if (b.test(j))
            {
                gap[j] = max(gap[j], i - last[j]);
                last[j] = i;
                has.set(j);
            }
        }
    }

    int ans = 1;
    for (int j = 0; j < 20; j++)
    {
        if (has.test(j))
        {
            gap[j] = max(gap[j], n - last[j] + 1);
            ans = max(ans, gap[j]);
        }
    }

    cout << ans << "\n";
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