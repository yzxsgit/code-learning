#include <iostream>

using namespace std;
bool st[100010];
int main()
{
    bool flag = false;
    int n = 0;
    int x, s;
    cin >> x >> s;
    if (s % x != 0 && 1000 % x == 0)
    {
        printf("-1\n");
    }
    else
    {
        int n = 1, tmp = s, k = 1000 % x, t = s % x, q = k;
        while (tmp % x != 0)
        {
            tmp = (tmp + q * t) % x;
            q = q * k % x;
            n++;
        }
        printf("%d", n);
    }
    return 0;
}