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

const int N = 1010, inf = 0x3f3f3f3f;

int f[N][N];
int n, m;
char str[N];
int tr[N][4], ne[N], idx;
bool dar[N];

void init()
{
    idx = 0;
    memset(tr, 0, sizeof tr);
    memset(dar, 0, sizeof dar);
    memset(ne, 0, sizeof ne);
    memset(f, 0x3f, sizeof f);
}

map<char, int> mp;

void insert()
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int t = mp[str[i]];
        if (!tr[p][t])
            tr[p][t] = ++idx;
        p = tr[p][t];
    }
    dar[p] = true;
}

void build()
{
    queue<int> q;
    for (int i = 0; i < 4; i++)
        if(tr[0][i])
            q.push(tr[0][i]);

    while (q.size())
    {
        int t = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
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
                dar[p] |= dar[ne[p]];
            }
        }
    }
}

void solve(int T)
{
    init();
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        insert();
    }

    build();

    f[0][0] = 0;

    cin >> str + 1;
    int m = strlen(str + 1);
    for (int i = 0; i < m; i++)
        for (int j = 0; j <= idx; j++)
            for (int k = 0; k < 4; k++)
            {
                int t = mp[str[i + 1]] != k;
                int p = tr[j][k];
                if (!dar[p])
                {
                    f[i + 1][p] = min(f[i + 1][p], f[i][j] + t);
                }
            }

    int res = 0x3f3f3f3f;
    for (int i = 0; i <= idx; i++)
        res = min(res, f[m][i]);

    cout << "Case " << T << ": " << (res == 0x3f3f3f3f ? -1 : res) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    mp['A'] = 0, mp['G'] = 1, mp['C'] = 2, mp['T'] = 3;

    int T = 1;
    while (cin >> n && n)
    {
        solve(T++);
    }
    return 0;
}