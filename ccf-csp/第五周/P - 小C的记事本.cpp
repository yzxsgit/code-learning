#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

const int N = 1e6 + 10;
string str[N];
int q, cnt, len[N];

int main()
{
    while (cin >> q)
    {
    stack<string> s;
    s.push("");
    while (q--)
    {
        int op;
        scanf("%d", &op);
        if(op == 1)
        {
            string in;
            cin >> in;
            s.push(s.top() + in);
        }
        else if(op == 2)
        {
            int k;
            scanf("%d", &k);
            string x = s.top();
            s.push(x.substr(0, x.length() - k));
        }
        else if(op == 3)
        {
            int k;
            scanf("%d", &k);
            string x = s.top();
            cout << x[k - 1] << endl;
        }
        else
            s.pop();
    }
    }

    return 0;
}