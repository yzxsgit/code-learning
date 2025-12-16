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

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += abs(a[i] - a[n / 2]);

    printf("%d\n", ans);

    return 0;
}