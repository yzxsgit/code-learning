#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int f[N];
int h[N];
int main()
{

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &h[i]);

    f[1] = 0;
    f[2] = abs(h[2] - h[1]);
    for (int i = 3; i <= n; i++)
        f[i] = min(f[i - 2] + abs(h[i] - h[i - 2]), f[i - 1] + abs(h[i] - h[i - 1]));

    cout << f[n] << endl;

    return 0;
}