#include <bits/stdc++.h>
using namespace std;

int k_to_d(string a, int k)
{
    int res = 0;
    for (auto i : a)
    {
        if (i >= '0' && i <= '9')
            res = res * k + i - '0';
        else
            res = res * k + i - 'A' + 10;
    }

    return res;
}
string d_to_k(int x, int k)
{
    string res = "";
    while (x)
    {
        int i = x % k;
        if (i >= 10)
            res = (char)(i + 'A' - 10) + res;
        else
            res = (char)(i + '0') + res;
        x /= k;
    }

    return res;
}
int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = k_to_d(s, k);
    cin >> k;
    cout << d_to_k(n, k) << endl;

    return 0;
}