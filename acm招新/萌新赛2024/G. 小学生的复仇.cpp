#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int a[N];
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]), a[i] = max(a[i], a[i - 1]);
    long long res = 0;
    for (int i = 0; i < n - 1; i++)
        res += a[i];
    printf("%lld\n", res);

    return 0;
}