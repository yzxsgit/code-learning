#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        int k;
        bool has_ans = false;
        for (int i = 30; i >= 0; i--)
        {
            if(a >> i && 1)
                has_ans = true;
            if (b >> i & 1 && !has_ans)
            {
                break;
            }
            else if (b >> i & 1)
            {
                k = i;
                break;
            }
        }
        if (!has_ans)
        {
            printf("-1\n");
            continue;
        }
        int x = 0, y = 0;
        for (int i = 30; i > k; i--)
            x += (a >> i & 1) * (1 << i);
        for (int i = k; i >= 0; i--)
            y += (b >> i & 1) * (1 << i);
        y = y ^ (a ^ x);
        if(x == 0)
            printf("1\n%d\n", y);
        else if(y == 0)
            printf("1\n%d\n", x);
        else
            printf("2\n%d %d\n", y, x);
    }
    return 0;
}