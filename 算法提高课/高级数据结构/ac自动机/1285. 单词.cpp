#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 1e6 + 10;

int cnt[N], tr[N][26], ne[N];
int idx;
char str[N];
int id[210];
int n;

vector<int> f;

void insert(int x)
{
    int p = 0;

    for (int i = 0; str[i]; i++)
    {
        int t = str[i] - 'a';
        if (!tr[p][t])
            tr[p][t] = ++idx;
        p = tr[p][t];
        cnt[p]++;
    }
    id[x] = p;
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
        f.push_back(t);
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        insert(i);
    }

    build();

    reverse(f.begin(), f.end());
    for (int i : f)
        cnt[ne[i]] += cnt[i];

    for (int i = 0; i < n; i++)
        cout << cnt[id[i]] << '\n';

    return 0;
}