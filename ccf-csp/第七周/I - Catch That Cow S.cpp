#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;
int d[N];
bool f[N];
void bfs(int begin, int end)
{
    queue<int> q;
    q.push(begin);
    d[begin] = 0;
    f[begin] = true;
    while (q.size())
    {
        int t = q.front();
        if (t == end)
            break;
        q.pop();

        int nx = t + 1;
        if (nx >= 0 && nx < 1e5 && !f[nx])
        {
            f[nx] = true;
            d[nx] = d[t] + 1;
            q.push(nx);
        }
        nx = t - 1;
        if (nx >= 0 && nx < 1e5 && !f[nx])
        {
            f[nx] = true;
            d[nx] = d[t] + 1;
            q.push(nx);
        }
        nx = t * 2;
        if (nx >= 0 && nx < 1e5 && !f[nx])
        {
            f[nx] = true;
            d[nx] = d[t] + 1;
            q.push(nx);
        }
    }
}
int main()
{
    int x, y, t;
    scanf("%d", &t);
    while (t--)
    {
        memset(d, 0x3f, sizeof d);
        memset(f, false, sizeof f);
        scanf("%d%d", &x, &y);

        bfs(x, y);

        printf("%d\n", d[y]);
    }

    return 0;
}