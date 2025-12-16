#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 55;
vector<int> INF(300);

vector<int> f[N][N];
int w[N];
int n;

bool cmp(vector<int> a, vector<int> b)
{
    if (a.size() != b.size())
        return a.size() > b.size();
    else
        for (int i = a.size() - 1; i >= 0; i--)
            if(a[i] != b[i])
                return a[i] > b[i];
    return 0;
}

vector<int> add(vector<int> a, vector<int> b)
{
    if(a.size() < b.size())
        return add(b, a);
    vector<int> c;
    int temp = 0;
    for (int i = 0; i < a.size(); i++)
    {
        temp += a[i];
        if(i < b.size())
            temp += b[i];
        c.push_back(temp % 10);
        temp /= 10;
    }
    if(temp)
        c.push_back(temp);

    return c;
}

vector<int> mul(vector<int> a, long long b)
{
    vector<int> c;
    long long t = 0;
    for (int i = 0; i < a.size() || t; i++)
    {
        if(i < a.size())
            t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }

    return c;
}

void print(vector<int> res)
{
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i];
}

int main()
{
    INF[150] = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    
    
    for (int len = 3; len <= n; len++) 
    {  
        for (int l = 1; l + len - 1 <= n; l++) 
        {
            int r = l + len - 1;
            for (int k = l + 1; k < r; k++) 
            {
                vector<int> current = mul(mul({w[l]}, w[r]), w[k]);
                current = add(add(current, f[l][k]), f[k][r]);
                if(f[l][r].empty() | cmp(f[l][r],current))
                    f[l][r] = current;
            }
        }
    }

    print(f[1][n]);

    return 0;
}