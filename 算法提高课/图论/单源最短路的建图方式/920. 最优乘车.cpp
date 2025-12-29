#include <iostream>
#include <sstream>
#include <cstring>
#include <queue>

using namespace std;
const int N = 510, INF = 0x3f3f3f3f;

int n, m;
bool g[N][N];
int stop[N];
int dist[N];
void bfs()
{
    memset(dist, 0x3f, sizeof dist);
    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (q.size())
    {
        int t = q.front();
        q.pop();

        for (int i = 1; i <= n; i++)
            if(g[t][i] && dist[t] + 1 < dist[i])
            {
                dist[i] = dist[t] + 1;
                q.push(i);
            }
    }
}

int main()
{
    cin >> m >> n;
    string line;
    cin.ignore();
    while (m--)
    {
        getline(cin, line);
        stringstream ssin(line);
        int cnt = 0, p;
        while (ssin >> p)
            stop[cnt++] = p;
        for (int i = 0; i < cnt; i++)
            for (int j = i + 1; j < cnt; j++)
                g[stop[i]][stop[j]] = true;
    }

    bfs();

    if(dist[n] == INF)
        cout << "NO\n";
    else
        cout << max(0, dist[n] - 1) << "\n";
    return 0;
}