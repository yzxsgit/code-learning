#include <iostream>

using namespace std;

void solve()
{
    int n;
    string k;
    cin >> n >> k;
    if(n == 1)
    {
        cout << "A C\n";
        return;
    }
    int ansl = 0, ansr = 2, tmp = 1;

    while (k.size() < n)
        k = '0' + k;
    // cout << k << endl;
    for (int i = 0; i < n; i++)
    {
        if (k[i] == '0')
            swap(ansr, tmp);
        else
            swap(ansl, tmp);
    }
    cout << char(ansl + 'A') << " " << char(ansr + 'A') << "\n";
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}