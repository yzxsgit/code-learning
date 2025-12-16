#include <iostream>

using namespace std;
const int N = 1010, M = 510;

int n, V1, V2;
int f[N][M];

int main()
{
    scanf("%d%d%d", &V1, &V2, &n);
    for (int i = 0; i < n; i++)
    {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        for (int j = V1; j >= v1; j--)
            for (int k = V2 - 1 ; k >= v2; k--)
                f[j][k] = max(f[j][k], f[j - v1][k - v2] + 1);
    }

    cout << f[V1][V2 - 1] << " ";
    int k = V2 - 1;
    while (k > 0 && f[V1][k - 1] == f[V1][V2 - 1])
        k--;
    cout << V2 - k << endl;

    return 0;
}