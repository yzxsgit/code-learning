#include <bits/stdc++.h>
using namespace std;
const int N = 31;
string a[N], b[N];
int h, w;
bool find(int begin,int i)
{
    for (int j = 0; j < w; j++)
    {
        if(a[i][j+begin] != b[0][j])
            return false;
    }
    return true;
}
bool pd(int i ,int j)
{
    for (int u = 0; u < h; u++)
    {
        for (int k = 0; k < w; k++)
        {
            if (a[(i + u) % h][k + j] != b[u][k])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    scanf("%d%d", &h, &w);
    
    for (int i = 0; i < h; i++)
        cin >> a[i], a[i] = a[i] + a[i];
    for (int i = 0; i < h; i++)
        cin >> b[i];

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            if(find(j,i))
            {
                if(pd(i,j))
                {
                    printf("Yes");
                    return 0;
                }
                // printf("i = %d j = %d\n", i, j);
            }
    }
    printf("No");
    return 0;
}
// ##########   ...##
// .#....#...   #...#
// .##...##..   #####
// ..##...##.   ...#.
