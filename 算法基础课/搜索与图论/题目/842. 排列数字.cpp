#include <bits/stdc++.h>
using namespace std;
int n;
int path[10];
bool flag[10];
void print(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i++)
            printf("%d ", path[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!flag[i])
        {
            path[u] = i;
            flag[i] = true;
            print(u + 1);
            flag[i] = false;
        }
    }
}
int main()
{
    scanf("%d", &n);
    print(0);
    return 0;
}