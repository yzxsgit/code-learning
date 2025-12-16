#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
typedef pair<int, int> PII;
const int N = 2e5 + 10, INF = 1e9;
int a[N], place[N];
bool st[N];
char b[N];
void solve()
{
    memset(st, 0, sizeof st);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    scanf("%s", b + 1);
    if (b[1] == '1' || b[n] == '1')
    {
        puts("-1");
        return;
    }
    int k = 0;
    vector<PII> q;
    for (int i = 1; i <= n; i++)
    {
        if(b[i] == '0')
            st[a[i]] = true;
        else
            q.push_back({a[i],i});
        place[a[i]] = i;
    }

    vector<PII> ans;
    sort(q.begin(), q.end());
    auto idx = q.begin();
    while (q.size() && k <= 5)
    {
        auto t = *idx;
        int i = t.second - 1, j = t.second + 1;
        if(st[i] && st[j] && place[i])
        {
            k++;
            ans.push_back(i, j);
        }
        else if (st[i])
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();

    return 0;
}