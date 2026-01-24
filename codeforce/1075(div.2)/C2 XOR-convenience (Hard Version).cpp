#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5 + 10;
int res[N];
bool st[N];

void solve()
{
    int length;
    cin >> length;

    for (int i = 1; i <= length; i++)
        st[i] = false;

    res[length] = 1;
    st[1] = true;

    for (int i = 2; i < length; i++)
    {
        int tmp = i ^ 1;
        res[i] = tmp;
        if (tmp <= length)
            st[tmp] = true;
        else 
        {
            cout << -1 << "\n";
            return;
        }
    }

    for (int i = 1; i <= length; i++)
    {
        if (!st[i])
        {
            if(i == length)
            {
                cout << -1 << "\n";
                return;
            }
            res[1] = i;
            break;
        }
    }

    for (int i = 1; i <= length; i++)
    {
        cout << res[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}