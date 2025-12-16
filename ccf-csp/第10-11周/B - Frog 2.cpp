#include <iostream>
#include <cstring>

using namespace std;
const int N = 1e5 + 10;
int h[N], f[N];
int n, k;
int main()
{
    memset(f, 0x3f, sizeof f);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    
    f[1] = 0;
    
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= min(k, i - 1); j++)
            f[i] = min(f[i], f[i - j] + abs(h[i] - h[i - j]));
    cout << f[n] << "\n";

    return 0;
}