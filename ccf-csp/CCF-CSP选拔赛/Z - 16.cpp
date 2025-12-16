#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    
    if (n == 1)
        printf("YES\n2 3\n");
    else if(n == 2 )
        printf("NO\n");
    else
        printf("YES\n%lld %lld\n", n - 1, n);
    return 0;
}