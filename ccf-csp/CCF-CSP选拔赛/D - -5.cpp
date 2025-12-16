#include <iostream>
#include <algorithm>

using namespace std;

char a[100100];
int main()
{
    int n;
    cin >> n;
    scanf("%s", a);

    for (int i = 0; i < n; i++)
        if(a[i]>='a'&&a[i]<='z')
            cout << a[i];
    for (int i = 0; i < n; i++)
        if (a[i] >= '0' && a[i] <= '9')
            cout << a[i];
    for (int i = 0; i < n; i++)
        if (a[i] >= 'A' && a[i] <= 'Z')
            cout << a[i];
    return 0;
}