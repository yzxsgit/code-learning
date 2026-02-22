#include <iostream>
using namespace std;

int dfs(int x)
{
    if(x == 3)
        return 1;
    else if(x <= 2)
        return 0;
    else
    {
        int y = x - (x / 3) * 2;
        return x / 3 + dfs(y);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n", dfs(n));
    }

    return 0;
}