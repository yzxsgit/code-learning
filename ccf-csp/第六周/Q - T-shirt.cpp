#include <iostream>

using namespace std;

int main()
{
    double a, b, c, x;
    cin >> a >> b >> c >> x;

    if (x <= a)
        printf("1");
    else if (x > b)
    {
        printf("0");
    }
    else
    {
        printf("%lf", c / (b - a));
    }

    return 0;
}