#include <iostream>

using namespace std;

int main()
{
    int a[3] = {125, 211, 214};
    int b[3] = {4, 6, 8};
    int n;
    cin >> n;
    for (int i = 0; i < 3; i++)
        if(n<=a[i])
        {
            printf("%d\n", b[i]);
            break;
        }

    return 0;
}