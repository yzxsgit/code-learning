#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solve() 
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ones;
    for (int i = 0; i < n; i++) 
    {
        if (s[i] == '1')
            ones.push_back(i);
    }

    if (ones.empty()) 
    {
        return (n + 2) / 3;
    }

    int res = ones.size();

    res += (ones[0] + 1) / 3;

    for (int i = 0; i < ones.size() - 1; i++) 
    {
        int gap = ones[i + 1] - ones[i] - 1;
        if (gap >= 3) 
        {
            res += gap / 3;
        }
    }

    res += (n  - ones.back()) / 3;

    return res;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) 
    {
        cout << solve() << "\n";
    }
    return 0;
}