#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;
int a[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n * 2; i++)
        scanf("%d", &a[i]);
    sort(a, a + n * 2);
    int i = 0;
    long long x = 0, y = 0;
    while (i < n * 2)
    {
        if(x < y)
            x += a[i];
        else
            y += a[i];
        i++;
    }
    cout << abs(x - y);

    return 0;
}