#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    string s = "";
    
    while (n)
    {
        if(n % 2)
        {
            s =  "A" + s;
            n--;
        }
        else
        {
            s =  "B" + s;
            n /= 2;
        }
    }
    
    cout << s;

    return 0;
}