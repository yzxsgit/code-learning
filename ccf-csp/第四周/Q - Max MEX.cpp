#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
bool a[N];
int n, k;

int main()
{
    cin >> n >> k;

    int t;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        if (t > 3e5)
            continue;
        else
            a[t] = true;
    }
    int cnt = k;
    for (int i = 0; i < k; i++)
    {
        if(!a[i])
        {
            cnt = i;
            break;
        }
    }

    printf("%d\n", cnt);
    return 0;
}