#include <iostream>
#include <cstring>

using namespace std;

const int N = 5010;
long long f[N];
int t[N], c[N];
int n, s;

int main()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        t[i] = a + t[i - 1];
        c[i] = b + c[i - 1];
    }

    memset(f, 0x3f, sizeof f);
    f[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            f[i] = min(f[i], f[j] + (c[i] - c[j]) * (long long)t[i] + (long long)s * (c[n] - c[j]));
        }
    }

    cout << f[n] << endl;

    return 0;
}