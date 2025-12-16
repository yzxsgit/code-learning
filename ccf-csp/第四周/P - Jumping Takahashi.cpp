#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
int n, x;
int a[101], b[101];
bool st[N];

int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        scanf("%d%d", &a[i], &b[i]);

    st[0] = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = x; j >= 0; j--)
        {
            if(st[j])
            {
                st[j] = false;
                if (j + a[i] <= x)
                    st[j + a[i]] = true;
                if (j + b[i] <= x)
                    st[j + b[i]] = true;
            }
        }
    }

    cout << (st[x] ? "Yes" : "No") << endl;

    return 0;
}