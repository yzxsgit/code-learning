#include <iostream>

using namespace std;

int out[11];
bool flag[11];
int n;

void dfs(int d)
{
    if(d == n)
    {
        for (int i = 0; i < n; i++)
            printf("%d ", out[i]);
        printf("\n");
    }

    for (int i = 1; i <= n; i++)
        if(!flag[i])
        {
            flag[i] = true, out[d] = i;
            dfs(d + 1);
            flag[i] = false;
        }
}

int main()
{
    cin >> n;
    
    dfs(0);

    return 0;
}