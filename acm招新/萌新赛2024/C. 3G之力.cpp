#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    int count = 0;
    int i = -1;
    int len = s.size();
    while ((i++) + 1 < len)
    {
        if (s[i] == '3' && s[i + 1] == 'G')
            count++;
    }

    cout << (count >= n ? "yes" : "No") << endl;
}