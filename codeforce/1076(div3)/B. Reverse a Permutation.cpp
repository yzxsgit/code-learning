#include <iostream>

using namespace std;

const int N = 2e5 + 10;

int a[N];
int n, l, r;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int tmp = n;
    l = 1, r = 1;
    for (int i = 1; i <= n; i++)
        if(tmp != a[i])
        {
            l = i;
            break;
        }
        else
            tmp--;

    for (int i = l; i <= n; i++)
        if(tmp == a[i])
        {
            r = i;
            break;
        }
    for (int i = 1; i < l ; i++)
        cout << a[i] << " ";

    for (int i = r; i >= l; i--)
        cout << a[i] << " ";

    for (int i = r + 1; i <= n; i++)
        cout << a[i] << " ";

    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}