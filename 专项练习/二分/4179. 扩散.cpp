#include <iostream>
#include <map>

using namespace std;

const int N = 51;
int d[N][N];
pair<int,int> node[N];
int n;

bool check(long long x)
{
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        bool has_ans = false;
        for (int j = 0; j < n; j++)
        {
            if (i != j && d[i][j] <= x * 2)
                has_ans = true;
        }
        flag = has_ans;
        if(!flag)
        {
            break;
        }
    }

    return flag;
}

long long bsearch(int l ,int r)
{
    while (l < r)
    {
        long long mid = (long long)l + r >> 1;
        if(check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    if(check(l))
        return l;
    else
        return l + 1;
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        node[i] = {x, y};
    }
    int MAX_D = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i][j] = abs(node[i].first - node[j].first) + abs(node[i].second - node[j].second), MAX_D = max(MAX_D, d[i][j]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    // long long ans = bsearch(0, MAX_D);

    cout << ans << endl;

    return 0;
}