#include <iostream>

using namespace std;
const int N = 2e5 + 10;

int parent[N];
int find(int x)
{
    if(parent[x] != x)
        parent[x] = find(parent[x]);

    return parent[x];
}

int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    int res = 0;
    while (m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if(find(a) == find(b))
            res++;
        else
        {
            parent[find(a)] = find(b);
        }
    }

    cout << res << endl;

    return 0;
}