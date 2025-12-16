#include <iostream>

using namespace std;

int main()
{
    int v, a, b, c;
    cin >> v >> a >> b >> c;

    int res = v % (a + b + c);
    if(res >= a)
        res -= a;
    else
    {
        cout << 'F';
        return 0;
    }
    if (res >= b)
        res -= b;
    else
    {
        cout << 'M';
        return 0;
    }
    if (res >= c)
        res -= c;
    else
    {
        cout << 'T';
        return 0;
    }
}