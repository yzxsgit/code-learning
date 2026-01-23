#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>

using namespace std;

typedef pair<int, int> PII;

const int N = 160;
const double INF = 1e20;

int n;
char g[N][N];
double dist[N][N], dmax[N];
PII q[N];

double get_dist(PII a, PII b)
{
    double dx = a.first - b.first, dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

void floyd()
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i].first >> q[i].second;
    for (int i = 0; i < n; i++)
        cin >> g[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else if(g[i][j] == '1')
                dist[i][j] = get_dist(q[i], q[j]);
            else
                dist[i][j] = INF;
        }

    floyd();

    double r1 = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
            if (dist[i][j] < INF / 2)
                dmax[i] = max(dist[i][j], dmax[i]);
        r1 = max(dmax[i], r1);
    }

    double r2 = INF;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dist[i][j] > INF / 2)
                r2 = min(r2, dmax[i] + dmax[j] + get_dist(q[i], q[j]));

    cout << fixed << setprecision(6) << max(r1, r2) << "\n";

    return 0;
}
