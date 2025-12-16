#include <bits/stdc++.h>
using namespace std;
void dfs(int x)
{
    for (int i = 14; i >= 0; i--)
    {
        if (x >= (1 << i))
        {
            if (i == 1)
                cout << "2";
            else if (i == 0)
                cout << "2(0)";
            else
            {
                cout << "2(";
                dfs(i);
                cout << ")";
            }
            x -= 1 << i;
            if (x != 0)
                cout << "+";
        }

    }
}
int main()
{
    int n;
    scanf("%d", &n);
    dfs(n);
    return 0;
}