#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sort(a, a + n);

    long long ans = 0;

    for (int i = 0; i < n; i++)
        ans += a[i] * (n - i - 1);

    printf("%lld\n", ans);

    return 0;
}