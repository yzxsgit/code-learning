#include <iostream>

using namespace std;
const int N = 1e7 + 10;
long long f[N];
int n, m;
int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        long long v, w;
        cin >> v >> w;
        for (int j = v; j <= m; j++)
            f[j] = max(f[j], f[j - v] + w);
    }

    cout << f[m] << endl;

    return 0;
}