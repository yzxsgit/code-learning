#include <iostream>
#include <unordered_map>

using namespace std;
const int N = 1e5 + 10;
unordered_map<int, int> mp;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        mp[a]++;
    }
    int res = 0;
    for (auto& i : mp)
    {
        res = max(res, i.second);
    }

    cout << res << endl;

    return 0;
}