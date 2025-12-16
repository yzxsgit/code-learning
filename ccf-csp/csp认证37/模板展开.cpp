#include <iostream>
#include <unordered_map>

using namespace std;
unordered_map<string, int> mp, flag;
unordered_map<string, string> ssmp;
const int mod = 1000000007;
int mmfind(string x)
{
    bool st = false;
    string tmp = "";
    int res = 0;
    for (int i = 0; i < x.size(); i++)
    {
        if(!st)
        {
            if(x[i] == '$')
                st = true;
            else if(x[i] != ' ')
                res++;
        }
        else 
        {
            if(x[i] != ' ')
                tmp = tmp + x[i];
            else
            {
                if(flag[tmp] == 1)
                    res = (res + mp[tmp]) % mod;
                else if (flag[tmp] == 2)
                    res = (res + mmfind(ssmp[tmp])) % mod;
                st = false;
                tmp = "";
            }
        }
        // cout << res << " ";
    }
    if(st)
    {
        if (flag[tmp] == 1)
            res = (res + mp[tmp]) % mod;
        else if (flag[tmp] == 2)
            res = (res + mmfind(ssmp[tmp])) % mod;
    }
    // cout << "\n";
    return res;
}

int main()
{
    
    int n;
    cin >> n;
    while(n--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            string x, y;
            cin >> x;
            getchar();
            getline(cin, y);
            mp[x] = mmfind(y);
            flag[x] = 1;
        }
        else if(op == 2)
        {
            string x, y;
            cin >> x;
            getchar();
            getline(cin, y);
            ssmp[x] = y;
            flag[x] = 2;
        }
        else
        {
            string x;
            cin >> x;
            int res = 0;
            if (flag[x] == 1)
                res = mp[x];
            else if (flag[x] == 2)
                res = mmfind(ssmp[x]);
            cout << res % mod<< "\n";
        }

    }

    return 0;
}