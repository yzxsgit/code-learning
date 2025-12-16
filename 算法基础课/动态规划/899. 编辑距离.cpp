#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char b[20], a[N][20];
int maxl;
int n, m;
int f[12][12];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", a[i]);

    while (m--)
    {
        scanf("%s %d", b, &maxl);
        int lenb = strlen(b);
        int ans = 0;
        for (int t = 0; t < n; t++)
        {
            int lena = strlen(a[t]);
            for (int i = 1; i < lena; i++)
                for (int j = 1; j < lenb; j++)
                    f[i][j] = 0x3f3f3f3f;

            for (int i = 1; i <= lena; i++)
                f[i][0] = i;
            for (int i = 1; i <= lenb; i++)
                f[0][i] = i;

            for (int i = 1; i <= lena; i++)
                for (int j = 1; j <= lenb; j++)
                {
                    f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
                    if (a[t][i - 1] == b[j - 1])
                        f[i][j] = min(f[i][j], f[i - 1][j - 1]);
                    else
                        f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
                }
            if (f[lena][lenb] <= maxl)
                ans++;
        }

        printf("%d\n", ans);
    }
    return 0;
}