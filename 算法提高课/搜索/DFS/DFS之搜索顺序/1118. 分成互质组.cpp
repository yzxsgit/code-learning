#include <iostream>
#include <cstring>

using namespace std;
const int N = 11;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int p[N];
int res = N;
int n;
int group[N][N];
bool st[N];

bool check(int group[],int len, int i)
{
    for (int j = 0; j < len; j++)
        if (gcd(p[group[j]], p[i]) > 1)
            return false;
    return true;
}

void dfs(int g,int g_len,int total_num,int start)
{
    if (g > res)
        return;

    if (total_num == n)
    {
        res = g;
        return;
    }

    bool flag = true;
    for (int i = start; i < n; i++)
        if (!st[i] && check(group[g], g_len, i))
        {
            st[i] = true;
            group[g][g_len] = i;
            dfs(g, g_len + 1, total_num + 1, i + 1);
            st[i] = false;
            flag = false;
        }

    if(flag)
        dfs(g + 1, 0, total_num, 0);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i];

    dfs(1, 0, 0, 0);

    cout << res << "\n";

    return 0;
}