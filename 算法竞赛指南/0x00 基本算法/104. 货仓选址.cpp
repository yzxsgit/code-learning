#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
int d[N];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &d[i]);

    sort(d, d + n);

    int res = 0;
    for (int i = 0; i < n; i++)
        res += abs(d[i] - d[n / 2]);

    cout << res << "\n";

    return 0;
}