#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, mod = 1e9 + 7;
long long f[N][2];
int h[N], e[N * 2], ne[N * 2], idx;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int x, int parent)
{
    if (f[x][0] != 0)  
        return;

    f[x][0] = f[x][1] = 1; 
    
    for (int i = h[x]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == parent) continue;
        
        dfs(j, x);
        
        f[x][0] = f[x][0] * (f[j][0] + f[j][1]) % mod;
        
        f[x][1] = f[x][1] * f[j][0] % mod;
    }
}

int main()
{
    memset(h, -1, sizeof h);
    int n;
    cin >> n;
    
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }

    dfs(1, -1);

    long long res = (f[1][0] + f[1][1]) % mod;
    cout << res << endl;

    return 0;
}