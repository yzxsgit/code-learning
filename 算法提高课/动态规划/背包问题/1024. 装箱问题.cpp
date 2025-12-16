#include <iostream>

using namespace std;
const int N = 2e5 + 10;
int f[N];
int n;
int main()
{
    int v;
    cin >> v >> n;
    for (int i = 0; i < n; i++)
    {
        int w;
        cin >> w;
        for (int j = v; j >= w; j--)
            f[j] = max(f[j], f[j - w] + w);
    }

    printf("%d", v - f[v]);

    return 0;
}