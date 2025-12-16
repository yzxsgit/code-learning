#include <iostream>

using namespace std;
const int N = 1e5 + 10;
long long f[N];
int n, W;
int main()
{
    cin >> n >> W;
    for (int i = 0; i < n; i++)
    {
        int v, w;
        cin >> w >> v;
        for (int j = W; j >= w; j--)
            f[j] = max(f[j], f[j - w] + v);
    }

    cout << f[W] << "\n";

    return 0;
}