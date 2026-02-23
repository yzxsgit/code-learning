#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>

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
    
    vector<int> sa = a, sb = b;
    sort(sa.begin(), sa.end()); 
    sort(sb.begin(), sb.end());
    if (sa != sb) 
    {
        cout << "NO\n";
        return; 
        
    }
    
    map<int, int> pos;
    for (int i = 0; i < n; i++) 
    {
        pos[a[i]] = i;
    }
    
    vector<int> perm(n);
    for (int i = 0; i < n; i++) 
    {
        perm[i] = pos[b[i]];
    }
    
    vector<bool> visited(n, false); 
    int cycles = 0; 
    
    for (int i = 0; i < n; i++) 
    {
        if (!visited[i]) 
        {
            cycles++;
            int j = i;
            while (!visited[j]) 
            {
                visited[j] = true;
                j = perm[j]; 
            }
        }
    }
    
    if ((n - cycles) % 2 == 0) 
    {
        cout << "YES\n";
    } 
    else 
    {
        cout << "NO\n";
    }
    
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