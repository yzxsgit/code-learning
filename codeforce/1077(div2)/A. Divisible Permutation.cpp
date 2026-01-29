#include <iostream>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    int k = n + 1 >> 1;
    int up = k + 1, down = k;
    int res[110];
    for (int i = 1; i <= n; i++)
    {
        if(i%2)
            res[i] = down--;
        else
            res[i] = up++;
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
    cout << '\n';
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}