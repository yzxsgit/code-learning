#include <iostream>

using namespace std;

int main()
{
    int x, y;
    scanf("%d.%d", &x, &y);
    
    printf("%d", x);
    
    if(y<=2)
        cout <<'-';
    else if(y>=7)
        cout << '+';

    return 0;
}