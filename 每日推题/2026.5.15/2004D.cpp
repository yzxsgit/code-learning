#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <functional>
#include <array>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;

const int inf = 0x3f3f3f3f;

vector<string> col = {"BG", "BR", "BY", "GR", "GY", "RY"};

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < 6; j++)
        {
            if (col[j] == s)
            {
                a[i] = j;
                break;
            }
        }
    }

    vector<vector<int>> pre(n, vector<int>(6, -inf));
    vector<vector<int>> suf(n, vector<int>(6, inf));

    vector<int> last(6, -inf);

    for (int i = 0; i < n; i++)
    {
        last[a[i]] = i;
        pre[i] = last;
    }

    last.assign(6, inf);

    for (int i = n - 1; i >= 0; i--)
    {
        last[a[i]] = i;
        suf[i] = last;
    }

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        x--, y--;

        int res = inf;

        for (int j = 0; j < 6; j++)
        {
            if (a[x] + j != 5 && a[y] + j != 5)
            {
                int p = pre[x][j];
                if (p > -inf / 2)
                    res = min(res, abs(x - p) + abs(p - y));

                p = suf[x][j];
                if (p < inf / 2)
                    res = min(res, abs(x - p) + abs(p - y));
            }
        }

        if (res >= inf / 2)
            res = -1;

        cout << res << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}