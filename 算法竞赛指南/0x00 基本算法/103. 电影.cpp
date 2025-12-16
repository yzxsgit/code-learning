#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
const int N = 2e5 + 10;
int b[N], c[N];
int main()
{
    int n;
    scanf("%d", &n);
    unordered_map<int, int> perfer;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        perfer[x]++;
    }
    pair<int, int> max_perfer;
    int res = 0;
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
        scanf("%d", &b[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &c[i]);
    res = 1;
    max_perfer = {perfer[b[1]], perfer[c[1]]};
    for (int i = 2; i <= m; i++)
    {
        int x = perfer[b[i]], y = perfer[c[i]];
        if (x > max_perfer.first || x == max_perfer.first && y > max_perfer.second)
        {
            res = i;
            max_perfer = {x, y};
        }
    }

    printf("%d", res);
    return 0;
}
