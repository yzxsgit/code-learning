#include <iostream>
#include <vector>

using namespace std;
const int N = 20, M = 1 << 12, mod = 1e8;
int f[N][M];
int n, m;

bool check(int state)
{
    for (int i = 0; i < n; i++)
        if (state >> i & 1 && state >> i + 1 & 1)
            return false;
    return true;
}

vector<int> state;
vector<int> head[M];
int g[N];
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            g[i] += !a * (1 << j);
        }

    for (int i = 0; i < 1 << n; i++)
        if (check(i))
            state.push_back(i);

    for (int i = 0; i < state.size(); i++)
        for (int j = 0; j < state.size(); j++)
        {
            int a = state[i], b = state[j];
            if (!(a & b))
                head[i].push_back(j);
        }

    f[0][0] = 1;
    for (int i = 1; i <= m + 1; i++)
        for (int a = 0; a < state.size(); a++)
            if (!(state[a] & g[i]))
                for (int b : head[a])
                    f[i][a] = (f[i][a] + f[i - 1][b]) % mod;

    cout << f[m + 1][0] << endl;

    return 0;
}