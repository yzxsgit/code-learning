#include <iostream>
#include <cstring>

using namespace std;

const int N = 310;

int w[N][N];
int dist[N];
bool st[N];
int n;

int prim()
{
    memset(dist, 0x3f, sizeof dist);

    dist[0] = 0;

    int res = 0;
    for (int i = 0; i <= n; i++)
    {
        int t = -1;

        for (int j = 0; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        res += dist[t];
        st[t] = true;
        for (int j = 0; j <= n; j++)
            dist[j] = min(dist[j], w[t][j]);
    }

    return res;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[0][i];
        w[i][0] = w[0][i];
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> w[i][j];

    cout << prim() << "\n";

    return 0;
}