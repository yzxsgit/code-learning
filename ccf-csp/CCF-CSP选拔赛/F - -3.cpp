#include <iostream>

using namespace std;

int main()
{
    string flag = "while",a;
    cin >> a;
    int res = 5;
    for (int i = 0; i < 5; i++)
        if (flag[i] == a[i])
            res--;
    cout << res;

    return 0;
}