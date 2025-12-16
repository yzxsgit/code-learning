#include <iostream>

using namespace std;

int a;
int main()
{
    int n, x;
    cin >> n >> x;
    int res = 0, maxx = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if (a <= x)
        {
            maxx = max(maxx, a);
            res++;
        }
    }

    cout << res << " " << x - maxx;

    return 0;
}