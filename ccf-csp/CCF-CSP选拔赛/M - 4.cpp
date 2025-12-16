#include <iostream>

using namespace std;

int gcd(int x,int y)
{
    return x % y == 0 ? y : gcd(y, x % y);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int c = gcd(a, b);
        int A = min(a, min(b, c));
        int B = max(a, max(b, c));
        int C = a + b + c - A - B;
        cout << (C + A > B ? "Yes" : "No") <<"\n";
    }

    return 0;
}