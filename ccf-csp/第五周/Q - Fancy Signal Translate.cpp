#include <iostream>
#include <set>

using namespace std;

int main()
{
    string s;
    cin >> s;
    for (int i = 1;;i++)
    {
        set<string> book;
        for (int j = 0; j + i <= s.size(); j++)
        {
            book.insert(s.substr(j, i));
        }
        if(book.size() < (1<<i))
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}