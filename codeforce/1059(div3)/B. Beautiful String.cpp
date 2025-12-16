#include <iostream>
#include <cstring>
using namespace std;

char s[30], p[30], q[30];
int n;

bool check(int len_p, int len_q)
{
    // 检查 p（剩余部分）是否是回文
    for (int i = 0; i < len_p / 2; i++)
    {
        if (p[i] != p[len_p - 1 - i])
            return false;
    }

    // 检查 q（选中的子序列）是否非递减
    for (int i = 1; i < len_q; i++)
    {
        if (q[i - 1] > q[i])
            return false;
    }
    return true;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        cin >> s;

        bool found = false;
        int best_mask = 0;
        int best_len_q = 0;

        for (int mask = 0; mask < (1 << n); mask++)
        {
            int len_p = 0, len_q = 0;

            // 根据mask分离p和q
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                {
                    q[len_q++] = s[i]; // q是选中的子序列
                }
                else
                {
                    p[len_p++] = s[i]; // p是剩余部分
                }
            }

            if (check(len_p, len_q))
            {
                found = true;
                best_mask = mask;
                best_len_q = len_q;
                break;
            }
        }

        if (found)
        {
            printf("%d\n", best_len_q);
            if (best_len_q > 0)
            {
                for (int i = 0; i < n; i++)
                {
                    if (best_mask & (1 << i))
                    {
                        printf("%d ", i + 1);
                    }
                }
                printf("\n");
            }
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}