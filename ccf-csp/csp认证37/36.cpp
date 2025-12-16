#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int a[N], b[N], c[N];
int n;
int main()
{
    cin >> n;

    for (int i = 0; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    c[0] = a[0];
    for (int i = 1; i <= n + 1; i++)
        c[i] = c[i - 1] - b[i] + a[i];

    for (int i = n; i >= 0; i--)
        c[i] = max(c[i], c[i + 1]);
        
    int res = a[0];
    for (int i = 1; i <= n; i++)
    {
        res = max(res, c[i]);
        printf("%d ", max(b[i] + c[i], res));
    }

    return 0;
}