#include <iostream>

using namespace std;
const int mod = 1e8 + 7, N = 6e3 + 10;
long long ctl[N];
int main()
{
    int n;
    cin >> n;
    ctl[0] = ctl[1] = 1;
    ctl[2] = 2;
    for (int i = 3; i <= n; i++)
        for (int j = 0; j < i; j++)
            ctl[i] = (ctl[i] + ctl[j] * ctl[i - j - 1]) % mod;

    cout << ctl[n] << endl;

    return 0;
}