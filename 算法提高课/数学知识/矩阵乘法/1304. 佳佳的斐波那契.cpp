#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 4;

int n, m;


void mul(int c[][N], int a[][N], int b[][N])
{
    int temp[N][N];

    memset(temp, 0, sizeof temp);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                temp[i][j] = (temp[i][j] + (i64)a[i][k] * b[k][j]) % m;

    memcpy(c, temp, sizeof temp);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    int f1[N][N] = {1, 1, 1, 0};

    int a[N][N] = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    };

    int k = n - 1;

    while (k)
    {
        if (k & 1)
            mul(f1, f1, a); // f1 = f1 * a
        mul(a, a, a);       // a = a * a
        k >>= 1;
    }

    cout << (((i64)n * f1[0][2] - f1[0][3]) % m + m) % m << '\n';

    return 0;
}