#include <iostream>
#include <vector>

using namespace std;
const int N = 12, M = 1 << N, INF = 0x3f3f3f3f;
int map[N][N];
int n, m;

int main()
{
    memset(map, 0x3f, sizeof map);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, v;
        cin >> a >> b >> v;
        map[a][b] = map[b][a] = min(map[a][b], v);
    }
}