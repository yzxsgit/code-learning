#include <iostream>

using namespace std;
const int N = 110;
int h[N];
int up[N], down[N];
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &h[i]);

    for (int i = 1; i <= n; i++)
    {
        up[i] = 1;
        for (int j = 1; j < i; j++)
            if (h[i] > h[j])
                up[i] = max(up[i], up[j] + 1);
    }

    for (int i = n; i >= 1; i--)
    {
        down[i] = 1;
        for (int j = n; j > i; j--)
            if(h[i] > h[j])
                down[i] = max(down[i], down[j] + 1);
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, up[i] + down[i] - 1);

    cout << n - res << "\n";

    return 0;
}