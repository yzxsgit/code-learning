#include <iostream>

using namespace std;

const int N = 1e5 + 10;

long long a[N], b[N];
int n, k;

bool check(int x)
{
    long long res = k;
    for (int i = 0; i < n; i++)
    {
        res -= (a[i] * x > b[i]) ? a[i] * x - b[i] : 0;
        if(res < 0)
            return false;
    }
    return true;
}

int bsearch(long long l,long long r)
{
    while (l < r)
    {
        long long mid = (long long)l + r >> 1;
        if(check(mid))
            l = mid + 1;
        else
            r = mid;
    }

    return l - 1;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);

    int ans = bsearch(0, 2e9 + 10);

    printf("%d\n", ans);

    return 0;
}