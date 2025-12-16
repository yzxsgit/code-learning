#include <iostream>
using namespace std;

int n;
int a[110];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int l = 0, r = n - 1;

    while (l < r)
    {
        int mid = l + r >> 1;
        if(a[mid] >= a[0])
            l = mid + 1;
        else
            r = mid;
    }
    printf("%d\n", a[l]);

    return 0;
}