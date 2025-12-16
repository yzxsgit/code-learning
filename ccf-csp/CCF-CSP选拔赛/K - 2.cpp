#include <iostream>

using namespace std;

int main()
{
    string a;
    cin >> a;
    int res = 0;
    for (int i = 0; i < a.size() - 1; i++)
        if (a[i] != a[i + 1])
            res++;

    cout << res;
}