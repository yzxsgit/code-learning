#include <iostream>

using namespace std;

int pmi(int a,int b,int p)
{
    int res = 1;
    a = a % p;
    while (b)
    {
        if(b & 1)
            res = (res * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int m, h;
        cin >> m >> h;
        int a, b, res = 0;
        while(h--)
        {
            cin >> a >> b;
            res = (res + pmi(a, b, m)) % m;
        }
        cout << res % m << '\n';
    }

    return 0;
}