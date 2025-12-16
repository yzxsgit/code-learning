#include <iostream>

using namespace std;
const int N = 1010, v[4] = {10, 20, 50, 100};
int f[N];

int main()
{
    int n;
    cin >> n;
    f[0] = 1;
    for (int i = 0; i < 4; i++)
        for (int j = v[i]; j <= n; j++)
            f[j] += f[j - v[i]];

    cout << f[n] << endl;

    return 0;
}