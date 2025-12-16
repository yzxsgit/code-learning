#include <bits/stdc++.h>
using namespace std;

bool l[101];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> l[i];
    
    int left = 0, right = n;
    for (int i = 1; i <= n; i++)
        if (!l[i])
            left = i;
        else 
            break;

    for (int i = n; i >= 1; i--)
        if(!l[i])
            right = i - 1;
        else
            break;
    
    printf("%d", max(right - left - 1,0));

    return 0;
}