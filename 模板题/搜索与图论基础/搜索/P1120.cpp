#include <iostream>
#include <algorithm>

using namespace std;

int a[70];
bool vis[70];
int n, sum, target_len, cnt;

bool dfs(int cab, int last_idx, int left_sticks)
{
    if (left_sticks == 0)
        return true;

    if (cab == target_len)
        return dfs(0, 1, left_sticks - 1);

    int fail = 0;

    for (int i = last_idx; i <= cnt; i++)
    {
        if (!vis[i] && cab + a[i] <= target_len && fail != a[i])
        {
            vis[i] = true;

            if (dfs(cab + a[i], i + 1, left_sticks))
                return true;

            vis[i] = false;
            fail = a[i]; 

            if (cab == 0 || cab + a[i] == target_len)
                return false;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    if (!(cin >> m))
        return 0;

    for (int i = 1; i <= m; i++)
    {
        int val;
        cin >> val;
        a[++cnt] = val;
        sum += val;
    }

    sort(a + 1, a + cnt + 1, greater<int>());

    for (target_len = a[1]; target_len <= sum / 2; target_len++)
    {
        if (sum % target_len != 0)
            continue;

        if (dfs(0, 1, sum / target_len))
        {
            cout << target_len << '\n';
            return 0;
        }
    }

    cout << sum << '\n';

    return 0;
}