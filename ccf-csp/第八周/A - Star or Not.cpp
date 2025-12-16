#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int l[N], r[N];
int main()
{
    int n;
    scanf("%d", &n);
    int flag = false;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        l[a]++;
        r[b]++;
        if (l[a] + r[a] == n - 1 || l[b] + r[b] == n - 1)
            flag = true;
    }

    cout << (flag ? "Yes" : "No");

    return 0;
}