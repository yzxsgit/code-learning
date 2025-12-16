#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e5 + 10;
bool can_be_used[N * 2];
int cost[N * 2];
int a[N * 2], b[N * 2];
int diviser[N * 2];
bool st[N * 2];

int find_diviser(int x)
{
    int cnt = 0;
    for (int i = 2; i < x / i; i++)
    {
        if(x % i == 0)
        {
            diviser[cnt++] = i;
            diviser[cnt++] = x / i;
        }
    }
    return cnt;
}

int n;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(can_be_used, false, sizeof can_be_used);
        memset(cost, 0x3f, sizeof cost);
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        int res = 0x3f3f3f3f;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= min(a[i], b[i]); j++)
            {
                if(can_be_used[a[i] + j] && a[i] + j != 1)
                {
                    res = min(res, j + cost[a[i] + j]);
                }
                can_be_used[a[i] + j] = true;
                cost[a[i] + j] = min(cost[a[i] + j], j);
            }
        }

        for (int i = 2; i <= 4e5; i++)
        {
            int k = 0x3f3f3f3f;
            if(can_be_used[i])
            {
                n = find_diviser(i);
                for (int j = 0; j < n; j++)
                    k = min(k, cost[diviser[j]]);
                k += cost[i];
            }
            res = min(k, res);
        }
        printf("%d\n", res);
    }

    return 0;
}