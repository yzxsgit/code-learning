#include <iostream>

using namespace std;
const int N = 1010;

int a[N][N];

void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
            printf("%d ", a[i][j]);
        puts("");
    }
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}