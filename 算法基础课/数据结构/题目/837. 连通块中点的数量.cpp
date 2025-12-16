#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int p[N], s[N];

int find(int x)
{
    if(x != p[x])
        p[x] = find(p[x]);
    return p[x];
}

int main() 
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        p[i] = i, s[i] = 1;
    while (m--)
    {
        char op[5];
        int a, b;
        scanf("%s", op);
        if(op[0] == 'C')
        {
            scanf("%d%d", &a, &b);
            if(find(a) != find(b))
            {
                s[find(b)] += s[find(a)];
                p[find(a)] = find(b);
            }
        }
        else
        {
            if(op[1] == '1')
            {
                scanf("%d%d", &a, &b);
                if(find(a) == find(b))
                    printf("Yes\n");
                else
                    printf("No\n");
            }
            else
            {
                scanf("%d", &a);
                printf("%d\n", s[find(a)]);
            }
        }
    }
    return 0;
}