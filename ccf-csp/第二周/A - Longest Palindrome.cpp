#include <bits/stdc++.h>
using namespace std;
char s[210], ss[110];
int p[210];
int manachar()
{
    int m = 0;
    s[0] = '$', s[++m] = '#';
    int n = strlen(ss);
    for (int i = 0; i < n; i++)
    {
        s[++m] = ss[i];
        s[++m] = '#';
    }
    s[++m] = '?';
    int id = 0, maxid = 0, maxx = 0;
    for (int i = 1; i < m; i++)
    {
        if (maxid > i)
            p[i] = min(maxid - i, p[2 * id - i]);
        else
            p[i] = 1;
        while (s[i - p[i]] == s[i + p[i]])
            p[i]++;
        if (i + p[i] > maxid)
        {
            maxid = i + p[i];
            id = i;
        }
        maxx = max(maxx, p[i] - 1);
    }
    // for (int i = 1; i < m; i++)
    //     printf("%c", s[i]);
    // printf("\n");
    // for (int i = 1; i < m; i++)
    //     printf("%d ", p[i]);
    // printf("\n");
    return maxx;
}
int main()
{
    cin >> ss;
    int ans = manachar();

    printf("%d", ans);

    return 0;
}