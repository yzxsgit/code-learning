#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int p[N], idx;
int find(int x)
{
    if(p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
int main() 
{
    int n,m;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    scanf("%d%d", &n, &m);
    while (m--)
    {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if(op[0] == 'M')
        {
            p[find(a)] = find(b);
        }
        else
        {
            if(find(a) == find(b))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}