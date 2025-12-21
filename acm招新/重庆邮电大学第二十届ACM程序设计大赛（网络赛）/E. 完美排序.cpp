#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
const int N = 1e4 + 10;
int a[N];
int n;

int main() 
{
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> a[i];

    int max_k = 0;

    for (int i = 0; i < n; i++) 
    {
        int maxx = 0;
        
        vector<bool> st(n + 1, false); 

        for (int j = i; j < n; j++) 
        {
            if (st[a[j]]) 
                break;
            
            st[a[j]] = true;
            maxx = max(maxx, a[j]);

            int len = j - i + 1;
            if (len == maxx) 
                max_k = max(max_k, len);
        }
    }

    cout << max_k << endl;
    
    return 0;
}