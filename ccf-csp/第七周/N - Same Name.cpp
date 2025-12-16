#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> S,T;
    bool flag = false;
    while (n-- && !flag)
    {
        string s, t;
        cin >> s >> t;
        for (int i = 0; i < S.size(); i++)
            if(s == S[i] && t == T[i])
                flag = true;
        S.push_back(s);
        T.push_back(t);
    }

    cout << (flag ? "Yes" : "No");

    return 0;
}