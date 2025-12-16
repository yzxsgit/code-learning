#include <iostream>

using namespace std;

const int N = 2e5 + 10;
int a[N], t;
int maxx[N];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            if(i != 0)
                maxx[i] = max(maxx[i - 1], a[i]);
            else
                maxx[i] = a[i];
        }
        for (int i = 0; i < n; i += 2)
            if(i == 0)
                res += max(0, a[i] - maxx[i + 1] + 1);
            else if(i == n - 1)
                res += max(0, a[i] - maxx[i - 1] + 1);
            else
                res += max(0, max(a[i] - maxx[i - 1] + 1, a[i] - maxx[i + 1] + 1));
        printf("%d\n", res);
    }

    return 0;
}