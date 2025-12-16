#include <iostream>

using namespace std;

int k, g, m;
int glass, mug;

int main()
{
    cin >> k >> g >> m;

    while (k--)
    {
        if (glass == g)
            glass = 0;
        else if (mug == 0)
            mug = m;
        else
        {
            if (mug >= g - glass)
            {
                mug -= g - glass;
                glass = g;
            }
            else
            {
                glass += mug;
                mug = 0;
            }
        }
    }

    printf("%d %d\n", glass, mug);

    return 0;
}