#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x, res = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if(i % 2) res ^= x;
    }

    if(res) puts("Yes");
    else
        puts("No");

    return 0;
}