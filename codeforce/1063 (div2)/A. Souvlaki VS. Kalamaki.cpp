#include <iostream>
#include <algorithm>

using namespace std;
const int N = 110;
int a[N];

void solve()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    sort(a + 1, a + n + 1);

    bool flag = true;
    for (int i = 2; i + 1 <= n; i += 2)
        if (a[i] != a[i + 1])
        {
            flag = false;
            break;
        }

    cout << (flag ? "YES" : "NO") << "\n";
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();

    return 0;
}