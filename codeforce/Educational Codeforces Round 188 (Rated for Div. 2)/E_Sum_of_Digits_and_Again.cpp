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

const int N = 9e5 + 10;

int sum[N];
int f[N];
vector<int> cand[N];

void pre()
{
    for (int i = 1; i < N; i++)
    {
        int tmp = i, s = 0;
        while (tmp)
        {
            s += tmp % 10;
            tmp /= 10;
        }
        sum[i] = s;
    }

    for (int i = 1; i <= 9; i++)
    {
        f[i] = i;
        if (i + f[i] < N)
        {
            cand[i + f[i]].push_back(i);
        }
    }

    for (int i = 10; i < N; i++)
    {
        f[i] = sum[i] + f[sum[i]];
        if (i + f[i] < N)
        {
            cand[i + f[i]].push_back(i);
        }
    }
}

string get_S(int x)
{
    string res = "";
    while (true)
    {
        res += to_string(x);
        if (x <= 9)
            break;
        x = sum[x];
    }
    return res;
}

void solve()
{
    string s;
    cin >> s;

    if (s.size() == 1)
    {
        cout << s << '\n';
        return;
    }

    int tot = 0;
    vector<int> cnt(10, 0);
    for (char c : s)
    {
        tot += c - '0';
        cnt[c - '0']++;
    }

    for (int x1 : cand[tot])
    {
        string T = get_S(x1);
        vector<int> cnt_T(10, 0);

        for (char c : T)
        {
            cnt_T[c - '0']++;
        }

        bool ok = true;
        for (int i = 0; i < 10; i++)
        {
            if (cnt_T[i] > cnt[i])
            {
                ok = false;
                break;
            }
        }

        if (ok)
        {
            vector<int> rem(10, 0);
            for (int i = 0; i < 10; i++)
            {
                rem[i] = cnt[i] - cnt_T[i];
            }

            string ans = "";

            for (int i = 1; i < 10; i++)
            {
                while (rem[i] > 0)
                {
                    ans += to_string(i);
                    rem[i]--;
                }
            }

            while (rem[0] > 0)
            {
                ans += to_string(0);
                rem[0]--;
            }

            ans += T;
            cout << ans << '\n';

            return;
        }
            
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pre();

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}