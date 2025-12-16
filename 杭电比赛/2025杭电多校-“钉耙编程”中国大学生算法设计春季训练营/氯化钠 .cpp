#include <iostream>

using namespace std;

const int N = 1e5 + 10;
typedef long long ll;

int a[N],maxQ[N], minQ[N];
int n, k;

ll check(int x)
{
    ll count = 0;

}
ll countGE(int X)
{
    ll count = 0;

    int maxHead = 0, maxTail = 0;
    int minHead = 0, minTail = 0;

    int r = 0;
    for (int l = 0; l < n; l++)
    {
        // 确保 r >= l
        if (r < l)
            r = l;

        // 如果当前窗口为空，初始化
        if (maxHead == maxTail)
        {
            maxQ[maxTail++] = r;
            minQ[minTail++] = r;
        }

        // 扩展右指针直到满足条件
        while (r < n)
        {
            int curMax = a[maxQ[maxHead]];
            int curMin = a[minQ[minHead]];

            if (curMax + curMin >= X)
            {
                break;
            }

            r++;
            if (r >= n)
                break;

            // 维护最大值队列（递减）
            while (maxHead < maxTail && a[maxQ[maxTail - 1]] <= a[r])
            {
                maxTail--;
            }
            maxQ[maxTail++] = r;

            // 维护最小值队列（递增）
            while (minHead < minTail && a[minQ[minTail - 1]] >= a[r])
            {
                minTail--;
            }
            minQ[minTail++] = r;
        }

        // 累加满足条件的子段数
        if (r < n)
        {
            count += (n - r);
        }

        // 移除左指针元素
        if (maxHead < maxTail && maxQ[maxHead] == l)
        {
            maxHead++;
        }
        if (minHead < minTail && minQ[minHead] == l)
        {
            minHead++;
        }
    }

    return count;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        int MAX_A = 0;
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]) ,MAX_A = max(MAX_A, a[i]);

        ll l = 0, r = MAX_A;
        while (l < r)
        {
            ll mid = l + r >> 1;
            if(countGE(mid) >= k)
                l = mid + 1;
            else
                r = mid;
        }

        printf("%lld\n", l);
    }
}