#include <iostream>

using namespace std;
typedef long long ll;
const int N = 20, M = 3e3 + 10;
ll f[M];
int main()
{
    int n, m;
    cin >> n >> m;
    f[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        for (int j = a; j <= m; j++)
            f[j] += f[j - a];
    }

    cout << f[m] << "\n";

    return 0;
}