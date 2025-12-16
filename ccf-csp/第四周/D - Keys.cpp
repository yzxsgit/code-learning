#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int c[N];
bool tof[N];
int n, m, k;
int ans;
int count(int x)
{
    int res = 0;
    while (x)
    {
        if (x & 1)
            res++;
        x >>= 1;
    }

    return res;
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);

    int t;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &t);
        int r;
        for (int j = 1; j <= t; j++)
        {
            scanf("%d", &r);
            c[i] += 1 << (r - 1);
        }

        char op;
        cin >> op;
        if (op == 'o')
            tof[i] = true;
        else
            tof[i] = false;
    }

    for (int i = 0; i < 1 << n; i++)
    {
        bool flag = true;
        for (int j = 0; j < m; j++)
        {
            int p = i & c[j];
            int res = count(p);
            if (res < k && tof[j] || res >= k && !tof[j])
            {
                flag = false;
                // printf("i:%d j: %d tof: %d res: %d  \n", i, j,tof[j] , res);
                break;
            }
        }

        if (flag)
            ans++;
    }

    printf("%d\n", ans);

    return 0;
}
