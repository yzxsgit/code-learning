#include <iostream>

using namespace std;
long long fib[1010] = {0, 1, 1};
int main()
{
    int t;
    cin >> t;
    for (int i = 3; i <= 1000; i++)
        fib[i] = fib[i - 2] + fib[i - 1];
    while (t--)
    {
        int k;
        long long l, r;
        scanf("%d%lld%lld", &k, &l, &r);

        cout << (l > r / fib[k] ? "Yes" : "No") << "\n";
    }

    return 0;
}