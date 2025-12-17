#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
const int N = 2e5 + 10;

int start, ed;
int st[N];

int bfs(int x)
{
    queue<int> q;
    q.push(x);
    st[x] = 0;
    if(x == ed)
        return st[x];
    while (q.size())
    {
        int t = q.front();
        q.pop();
        int nx;

        nx = t - 1;
        if (nx >= 0 && nx <= 2e5 && st[nx] == -1)
        {
            st[nx] = st[t] + 1;
            if(nx == ed)
                return st[nx];
            q.push(nx);
        }
        nx = t + 1;
        if (nx >= 0 && nx <= 2e5 && st[nx] == -1)
        {
            st[nx] = st[t] + 1;
            if(nx == ed)
                return st[nx];
            q.push(nx);
        }
        nx = t * 2;
        if (nx >= 0 && nx <= 2e5 && st[nx] == -1)
        {
            st[nx] = st[t] + 1;
            if(nx == ed)
                return st[nx];
            q.push(nx);
        }
    }

    return -1;
}

int main()
{
    memset(st, -1, sizeof st);

    cin >> start >> ed;

    cout << bfs(start) << endl;

    return 0;
}