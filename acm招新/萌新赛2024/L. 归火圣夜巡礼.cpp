#include <iostream>

using namespace std;

int main()
{
    int q;
    cin >> q;
    string s;
    while (q--)
    {
        cin >> s;
        bool flag = true;
        string out = "";
        for (int i = 0; i < s.size(); i++)
        {
            if ('A' <= s[i] && s[i] <= 'Z' )
            {
                if(flag)
                    out = out + (char)(s[i]), flag = false;
                else
                    out = out + (char)(s[i] + 'a' - 'A');
            }
            else if('a' <= s[i] && s[i] <= 'z')
            {
                if (flag)
                    out = out + (char)(s[i] + 'A' - 'a'), flag = false;
                else
                    out = out + (char)(s[i]);
            }
            else 
            {
                flag = true;
            }
        }
        cout << out << "\n";
    }
    return 0;
}