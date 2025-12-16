#include <iostream>

using namespace std;

const int N = 110;
int num[N];
int n;
int c;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    int l = 0, r = n - 1;
    while (l < r)
    {
        int mid = l + r + 1>> 1;
        if(num[mid] > mid)
            r = mid - 1;
        else
            l = mid;
    }

    if (l != num[l])
        l = -1;
    printf("%d\n", l);

    return 0;
}