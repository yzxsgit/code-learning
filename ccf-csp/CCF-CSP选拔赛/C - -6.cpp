#include<iostream>

using namespace std;

int main()
{
    string a;
    cin >> a;
    for (int i = 0; i < a.size()/2; i++)
        cout << a[i];
    puts("");
    for (int i = a.size() / 2; i < a.size(); i++)
        cout << a[i];

    return 0;
}