#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
const int N = 5010;

PII city[N];
int f[N];
int n;

int main()
{
    scanf("%d", &n);
    int a, b;
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d%d", &a, &b);
        city[i] = {a, b};
    }
    sort(city + 1, city + 1 + n);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            if(city[j].second < city[i].second)
                f[i] = max(f[i], f[j] + 1);

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, f[i]);

    printf("%d\n", res);

    return 0;
}