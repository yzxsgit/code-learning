#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y;
    cin >> x >> y;
    if (x - y >= -2 &&x - y <= 3)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}