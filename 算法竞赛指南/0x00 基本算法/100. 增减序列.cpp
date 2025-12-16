#include <iostream>

using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
ll a[N];
int n;
ll pos, neg;
void insert(int l, int r, int x)
{
    a[l] += x;
    a[r + 1] -= x;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        insert(i, i, x);
    }

    for (int i = 2; i <= n; i++)
        if (a[i] > 0)
            pos += a[i];
        else
            neg -= a[i];

    cout << min(pos, neg) + abs(pos - neg) << "\n";
    cout << abs(pos - neg) + 1;

    return 0;
}