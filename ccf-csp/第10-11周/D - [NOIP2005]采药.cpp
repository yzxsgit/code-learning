#include <iostream>

using namespace std;
const int N = 1010;
int f[N];
int t, n;
int main()
{
    cin >> t >> n;
    for (int i = 0; i < n; i++)
    {
        int v, w;
        cin >> v >> w;
        for (int j = t; j >= v; j--)
            f[j] = max(f[j], f[j - v] + w);
    }

    cout << f[t] << "\n";

    return 0;
}