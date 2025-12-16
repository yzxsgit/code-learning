#include <bits/stdc++.h>
using namespace std;

long long f(long long a)
{
    long long res = 0;
    while(a)
    {
        res = res * 10 + a % 10;
        a /= 10;
    }

    return res;
}

int main()
{
    long long x, y;
    cin >> x >> y;
    int n = 8;
    while (n--)
    {
        long long z = f(x + y);
        x = y;
        y = z;
    }

    cout << y << endl;
}