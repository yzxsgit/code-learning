#include <iostream>

using namespace std;

int a[10];

int main()
{
    for (int i = 0; i <= 9;i++)
        cin >> a[i];
    int n = 2,i = 0;
    while (n--)
        i = a[i];
    printf("%d", a[i]);

    return 0;
}