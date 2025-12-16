#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
int h[N], e[N], ne[N];
int idx;
void insert(int x)
{
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}
bool find(int x)
{
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i])
        if (e[i] == x)
            return true;
    return false;
}
int main()
{
    memset(h, -1, sizeof h);
    int n;
    scanf("%d", &n);
    while (n--)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        if(op[0] == 'I')
            insert(x);
        else
        {
            if(find(x))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}