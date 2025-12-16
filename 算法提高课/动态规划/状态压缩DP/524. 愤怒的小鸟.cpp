#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 18, M = 1 << 18;
const double eps = 1e-6;
typedef pair<double, double> PDD;

int n, m;
PDD q[N];
int path[N][N];
int f[M];

int cmp(double x, double y)
{
    if (fabs(x - y) < eps) return 0;
    else if(x > y)
        return 1;
    return -1;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> q[i].first >> q[i].second;

    memset(path, 0, sizeof path);

    for (int i = 0; i < n; i++)
    {
        path[i][i] = 1 << i;
        for (int j = 0; j < n; j++)
        {
            double x1 = q[i].first, y1 = q[i].second, x2 = q[j].first, y2 = q[j].second;
            if(!(cmp(x1,x2))) continue;
            double a = (y1 / x1 - y2 / x2) / (x1 - x2);
            double b = y1 / x1 - a * x1;

            if (cmp(a, 0) >= 0) continue;
            int state = 0;
            for (int k = 0; k < n; k++)
            {
                double x = q[k].first, y = q[k].second;
                if (!cmp(a * x * x + b * x, y))
                    state += 1 << k;
            }
            path[i][j] = state;
        }
    }

    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    for (int i = 0; i + 1 < 1 << n; i++)
    {
        int x = 0;
        for (int j = 0; j < n; j++)
            if (!(i >> j & 1))
            {
                x = j;
                break;
            }
        for (int j = 0; j < n; j++)
            f[i | path[x][j]] = min(f[i] + 1, f[i | path[x][j]]);
    }

    cout << f[(1 << n) - 1] << "\n";
}

int main()
{
    int t;
    cin >> t;
    
    while (t--)
        solve();

    return 0;
}