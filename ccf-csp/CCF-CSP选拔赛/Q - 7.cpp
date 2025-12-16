#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int N = 1e5 + 10;
unordered_map<int, vector<int>> factors;
int flag;
void divide(int x)
{
    for (int i = 2; i <= x; i++)
    {
        int t = 0;
        while (x % i == 0)
        {
            t++;
            x /= i;
        }
        if(t != 0)
            factors[t].push_back(i);
        flag = t;
    }
    if (x > 1)
        factors[1].push_back(x);
}
int change(int a,int b)
{
    int x = 1;
    while (b--)
        x *= a;
    return x;
}
int n;
int main()
{
    cin >> n;
    cout << n << "\n";
    divide(n);
    if(factors.size()==1)
    {
        int a = 1;
        while (factors[flag].size())
        {
            a *= factors[flag].back();
            factors[flag].pop_back();
        }
        vector<pair<int,int>> out;
        int len = 0;
        for (int i = 1; i <= flag; i++)
            if (flag % i == 0)
                out.push_back({change(a, i), flag / i}), len++;

        for (auto i = len - 1; i >= 0; i--)
        {
            cout << "=" << out[i].first << "^" << out[i].second << "\n";
        }
    }
    else
        cout << "=" << n << "^1\n";

    return 0;
}