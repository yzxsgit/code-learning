#include <iostream>
#include <cstring>
using namespace std;
const int N = 110;
int x, y, a, b;
int main()
{
    cin >> a >> b >> x >> y;
    int res;
    if(a > b)
    {
        if(x * 2 < y)
        {
            res = ((a - b) * 2 - 1) * x;
        }
        else 
        {
            res = y * (a - b - 1) + x;
        }
    }
    else 
    {
        if(x * 2 < y)
        {
            res = ((b - a) * 2 + 1) * x;
        }
        else
        {
            res = (b - a) * y + x;
        }
    }

    printf("%d\n", res);
}