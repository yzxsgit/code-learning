#include <iostream>

using namespace std;

int n;
bool flag[20];

void put()
{
    for (int i = 1; i <= n; i++)
        if(flag[i])
            printf("%d ", i);
    puts("");
}

void dfs(int t)
{
    if(t > n)
        return;
    for (int i = t + 1;i <= n;i++)
    {
        if(!flag[i])
        {
            flag[i] = 1;
            put();
            dfs(i);
            flag[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    puts("");
    dfs(0);
    return 0;
}