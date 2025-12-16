#include <iostream>

using namespace std;

bool flag[30];
int n, m;
void dfs(int d,int t)
{
    if(d == m)
    {
        for (int i = 1; i <= n; i++)
            if(flag[i])
                printf("%d ", i);
        puts("");
    }

    for (int i = t + 1; i <= n; i++)
    {
        if(!flag[i]) 
        {
            flag[i] = true;
            dfs(d + 1, i);
            flag[i] = false;
        }
    }
}

int main()
{
    cin >> n >> m;
    
    dfs(0, 0);

    return 0;
}