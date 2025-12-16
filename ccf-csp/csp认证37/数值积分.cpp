#include <iostream>

using namespace std;
long long s;
int main()
{
    int b, c, l, r;
    cin >> b >> c >> l >> r;

    if(l % 2 != 0)
        l++;

    for (int i = l; i <= r; i += 2)
        s += i * i + b * i + c;
    s *= 2;

    cout << s << endl;

    return 0;
}