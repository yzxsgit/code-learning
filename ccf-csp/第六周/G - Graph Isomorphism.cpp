#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10;
int n, m;
int graph1[N][N], graph2[N][N];
int perm[N];
bool used[N];

void generatePerm(int pos,int n,bool &found)
{
    if (found)
        return;

    if (pos > n)
    {
        bool flag = true;
        for (int i = 1; i <= n && flag; i++)
            for (int j = i + 1; j <= n && flag; j++)
                if(graph1[i][j] != graph2[perm[i]][perm[j]])
                    flag = false;

        if(flag)
            found = true;
        return;
    }

    for (int i = 1; i <= n; i++)
        if(!used[i])
        {
            used[i] = true;
            perm[pos] = i;
            generatePerm(pos + 1, n, found);
            used[i] = false;
        }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        graph1[a][b] = graph1[b][a] = true;
    }

    for (int i = 0; i < m; i++)
    {
        int c, d;
        scanf("%d%d", &c, &d);
        graph2[c][d] = graph2[d][c] = true;
    }

    bool found = false;
    generatePerm(1, n, found);

    cout << (found ? "Yes" : "No") << endl;

    return 0;
}