#include<iostream>

using namespace std;
const int N = 100;
int road[N];
int n, m;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a,b;
        scanf("%d%d", &a, &b);
        road[a]++, road[b]++;
    }

    for (int i = 1; i <= n; i++)
        printf("%d\n", road[i]);

    return 0;
}