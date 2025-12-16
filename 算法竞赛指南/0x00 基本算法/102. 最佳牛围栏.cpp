#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int cow[N];
double sum[N];

int n, f;

bool check(double avg)
{
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + cow[i] - avg;

    double minv = 0;
    for (int i = 0, j = f; j <= n; i++,j++)
    {
        minv = min(minv, sum[i]);
        if(sum[j] - minv >= 0)
            return true;
    }

    return false;
}

int main()
{
    scanf("%d%d", &n, &f);
    double l = 0,r = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &cow[i]);
        r = max(r, (double) cow[i]);
    }

    while (r - l > 1e-5)
    {
        double mid = (l + r) / 2;
        if(check(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%d\n", (int)(r * 1000));

    return 0;
}