#include <iostream>
#include <vector>

using namespace std;
const int N = 110, M = 1 << 10;
int f[2][M][M];
int n, m;
int count(int state)
{
    int res = 0;
    for (int i = 0; i < m; i++)
        res += state >> i & 1;
    return res;
}
int s[M];
vector<int> state;
vector<int> head[M];
int g[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++)
        {
            char a;
            cin >> a;
            if(a == 'H')
                g[i] += 1 << j;
        }

    for (int i = 0; i < 1 << m; i++)
        if (!((i & i << 1) || (i & i << 2)))
        {
            state.push_back(i);
            s[i] = count(i);
        }

    
    for (int i = 1; i <= n + 2; i++)
        for (int j = 0; j < state.size(); j++)
            for (int k = 0; k < state.size(); k++)
                for (int u = 0; u < state.size(); u++)
                {
                    int a = state[j], b = state[k], c = state[u];
                    if (a & b | a & c | b & c) continue;
                    if (g[i] & b | g[i - 1] & a) continue;
                    f[i & 1][j][k] = max(f[i & 1][j][k], f[i - 1 & 1][u][j] + s[b]);
                }

    cout << f[n + 2 & 1][0][0] << "\n";

    return 0;
}