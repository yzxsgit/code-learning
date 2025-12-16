#include <iostream>

using namespace std;

int main()
{
    string a, b;
    cin >> a;
    b = a;
    int res1 = 0;
    for (int i = 1; i < a.size(); i++)
        if (a[i] == a[i - 1])
        {
            a[i] = '1' + '0' - a[i];
            res1 += i + 1;
        }
    int res2 = 1;
    
    b[0] = '1' + '0' - b[0];
    for (int i = 1; i < b.size(); i++)
        if (b[i] == b[i - 1])
        {
            b[i] = '1' + '0' - b[i];
            res2 += i + 1;
        }
    cout << min(res1, res2);
    return 0;
}