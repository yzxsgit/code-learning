#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 70;

int n;
int w[N];
int sum, len;
bool st[N];

bool dfs(int u, int cur, int start)
{
    if (u * len == sum)
        return true;
    if (cur == len)
        return dfs(u + 1, 0, 0);

    for (int i = start; i < n; i++)
    {
        if (st[i] || w[i] + cur > len)
            continue;

        st[i] = true;
        if (dfs(u, cur + w[i], i + 1))
            return true;
        st[i] = false;
    
        if(cur == 0)
            return false;
        
        if(cur + w[i] == len)
            return false;

        int j = i;
        while (j < n && w[j] == w[i])
            j++;
        
        i = j - 1;
    }

    return false;
}

void solve()
{
    memset(st, 0, sizeof st);

    sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
        sum += w[i];
    }

    sort(w, w + n, greater<int>());

    len = 1;
    while (true)
    {
        if (sum % len == 0 && dfs(0, 0, 0))
        {
            cout << len << "\n";
            break;
        }
        else
            len++;
    }
}

int main()
{
    while (cin >> n, n)
    {
        solve();
    }

    return 0;
}