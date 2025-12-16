#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main()
{
    int q;
    unordered_map<string, unordered_set<string>> mp; 

    cin >> q;
    while (q--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            string x, y;
            cin >> x >> y;
            mp[x].insert(y);
        }
        else if (op == 2)
        {
            string x;
            cin >> x;
            cout << mp[x].size() << "\n"; 
        }
        else if (op == 3)
        {
            string x, y;
            cin >> x >> y;
            if (mp.find(x) != mp.end() && mp[x].find(y) != mp[x].end())
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else
        {
            cout << mp.size() << "\n";
        }
    }

    return 0;
}