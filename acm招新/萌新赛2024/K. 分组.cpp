#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int f[N];
int n, q;
bool st[N];

int find(int x)
{
    if(f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        f[i] = i;

    while (q--)
    {
        int root, k;
        scanf("%d", &k);
        if (!k)
            continue;
        k--;
        scanf("%d", &root);
        root = find(root);
        while (k--)
        {
            int a;
            scanf("%d", &a);
            f[find(a)] = root;
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) 
        if(!st[find(i)])
            res++, st[find(i)] = true;

    printf("%d\n", res);

    return 0;
}