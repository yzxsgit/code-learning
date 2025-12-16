#include <iostream>

using namespace std;

int main()
{
    int a, b, n;
    int res = 0;
    cin >> n >> a >> b;
    for (int i = 0; i <= n / a; i++)
        for (int j = 0; j <= n / b; j++)
            if(i*a+j*b<=n)
                res = max(i + j, res);

    cout << res;

    return 0;
}