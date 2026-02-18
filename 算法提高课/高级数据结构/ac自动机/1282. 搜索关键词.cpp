#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 1e4 + 10, M = 1e6 + 10, S = 55;

int n;
int tr[N * S][26];
int cnt[N * S];
int idx;
char str[M];
int ne[N * S];

void init()
{
    idx = 0;
    memset(tr, 0, sizeof tr);
    memset(cnt, 0, sizeof cnt);
    memset(ne, 0, sizeof ne);
}

void insert()
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int t = str[i] - 'a';
        if (!tr[p][t])
            tr[p][t] = ++idx;
        p = tr[p][t];
    }
    cnt[p]++;
}

void build()
{
    queue<int> q;

    for (int i = 0; i < 26; i++)
        if (tr[0][i])
            q.push(tr[0][i]);
        
    while (q.size())
    {
        int t = q.front();
        q.pop();

        for (int i = 0; i < 26; i++)
        {
            int p = tr[t][i];
            if (!p)
            {
                tr[t][i] = tr[ne[t]][i];
            }
            else 
            {
                ne[p] = tr[ne[t]][i];
                q.push(p);
            }
        }
    }
}

void solve()
{
    init();
    cin >> n;
    while (n--)
    {
        cin >> str;
        insert();
    }
    build();

    cin >> str;
    int res = 0;
    for (int i = 0, j = 0; str[i]; i++)
    {
        int t = str[i] - 'a';
        j = tr[j][t];
        int p = j;
        while (p)
        {
            res += cnt[p];
            cnt[p] = 0;
            p = ne[p];
        }
    }

    cout << res << '\n';
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