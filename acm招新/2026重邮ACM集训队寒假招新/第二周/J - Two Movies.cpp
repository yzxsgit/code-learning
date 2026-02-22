#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

void solve()
{
int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    for (int i = 0; i < n; i++) 
        cin >> b[i];

    int A = 0, B = 0;
    int pos = 0;
    int neg = 0; 

    for (int i = 0; i < n; i++) 
    {
        if (a[i] > b[i]) 
        {
            A += a[i];
        } 
        else if (b[i] > a[i]) 
        {
            B += b[i];
        } 
        else if (a[i] == 1) 
        {
            pos++;
        } 
        else if (a[i] == -1) 
        {
            neg++;
        }
    }

    
    while (pos--) 
    {
        if (A < B) A++;
        else B++;
    }

    while (neg--) 
    {
        if (A > B) A--;
        else B--;
    }

    cout << min(A, B) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}