#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int op[N], num[N];
int n, m;

bool calc(bool x,int j)
{
    for (int i = 0; i < n; i++)
    {
        if(op[i] == 1)
            x &= num[i] >> j & 1;
        else if (op[i] == 2)
            x |= num[i] >> j & 1;
        else
            x ^= num[i] >> j & 1;
    }

    return x;
}

int main()
{
    scanf("%d%d", &n, &m);

    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str >> num[i];
        if(str[0] == 'A')
            op[i] = 1;
        else if (str[0] == 'O')
            op[i] = 2;
        else
            op[i] = 3;
    }

    int ans = 0;

    for (int i = 29; ~i; i--)
    {
        if (1 << i <= m)
        {
            bool x = calc(1, i), y = calc(0, i);
            if(y >= x)
                ans |= y << i;
            else
                ans |= x << i, m -= 1 << i;
        }
        else
            ans |= calc(0, i) << i;
    }

    printf("%d\n", ans);

    return 0;
}