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

const int N = 11;

int cnt[N];
i64 ans;

bool dfs(int i)
{
    if (i == 11)
    {
        return true;
    }

    i64 tmp = ans;
    for (int j = 10 - i; j <= 9; j++)
    {
        if (cnt[j])
        {
            cnt[j]--;
            ans = ans * 10 + j;
            if (dfs(i + 1))
                return true;
            cnt[j]++;
            ans = tmp;
        }
    }

    return false;
}

void solve()
{
    memset(cnt, 0, sizeof cnt);
    ans = 0;
    i64 x;
    cin >> x;
    for (int i = 1; i <= 10; i++)
    {
        cnt[x % 10]++;
        x /= 10;
    }
    
    dfs(1);

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