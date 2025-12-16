#include <iostream>

using namespace std;

int main()
{
    int n[11] = {0 ,2, 3, 4, 5, 6, 7, 8, 9, 10, 1};
    int a, b;
    cin >> a >> b;
    if(n[a] == b || n[b] == a)
        printf("Yes");
    else
        printf("No");
    return 0;
}