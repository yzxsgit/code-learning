#include<iostream>
using namespace std;
int num[5];
int main()
{
    for (int i = 1; i <= 3; i++)
    {
        int a, b;
        cin >> a >> b;
        num[a]++, num[b]++;
    }
    bool res = true;
    for (int i = 1; i <= 4; i++)
        if (!(num[i] == 1 || num[i] == 2))
            res = false;

    cout << (res ? "YES" : "NO");

    return 0;
}