#include <iostream>

using namespace std;
const int N = 110;
int n, M, V;
int f[N][N];
int v, m, w;

int main()
{
    cin >> n >> V >> M;
    for (int i = 0; i < n; i++)
    {
        cin >> v >> m >> w;
        for (int j = M; j >= m; j--)
            for (int k = V; k >= v;k--)
                f[j][k] = max(f[j][k] , f[j - m][k - v] + w);
    }

    cout << f[M][V] << endl;

    return 0;
}