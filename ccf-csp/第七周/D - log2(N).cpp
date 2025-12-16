#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    int res = 0;
    while (n >>= 1)
        res++;
    cout << res << "\n";
    return 0;
}