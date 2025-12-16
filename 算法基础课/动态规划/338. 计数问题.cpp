#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 10;

int get(vector<int> a,int l,int r)
{
    int res = 0;
    for (int i = l; i >= r; i--)
        res = res * 10 + a[i];
    return res;
}

int pow10(int x)
{
    int res = 1;
    while (x--)
        res *= 10;
    return res;
}

int count(int n,int x)
{
    if(!n)
        return 0;
    
    vector<int> num;
    while (n)
    {
        num.push_back(n % 10);
        n /= 10;
    }

    n = num.size();

    int res = 0;
    for (int i = n - 1 - !x; i >= 0; i--)
    {
        if (i < n - 1)
        {
            res += get(num, n - 1, i + 1) * pow10(i);
            if(!x)
                res -= pow10(i);
        }
        if(num[i] == x)
            res += get(num, i - 1, 0) + 1;
        else if (num[i] > x)
            res += pow10(i);
    }

    return res;
}

int main()
{
    int a, b;
    while (cin >> a >> b, a | b)
    {
        if (a < b)
            swap(a, b);
        for (int i = 0; i < 10; i++)
            cout << count(a, i) - count(b - 1, i) << " ";
        cout << endl;
    }
}