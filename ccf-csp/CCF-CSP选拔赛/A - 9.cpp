#include <iostream>

using namespace std;

int main()
{
    char a, b;
    a = getchar();
    getchar();
    b = getchar();
    cout << (a == b ? "YES" : "NO");
    return 0;
}