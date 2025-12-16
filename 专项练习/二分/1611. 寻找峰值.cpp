#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int num[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    int l = 0, r = n - 1, mid;
    while (l < r)
    {
        mid = l + r + 1>> 1;
        if(num[mid] > num[mid - 1])
            l = mid;
        else
            r = mid - 1;
    }

    printf("%d\n", l);

    return 0;
}