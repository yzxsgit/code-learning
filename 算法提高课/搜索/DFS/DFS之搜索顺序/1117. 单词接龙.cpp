#include <iostream>
#include <cstring>

using namespace std;
const int N = 30, M = N * N;
string str[N];
int n;
bool st[N];
int ans;

void dfs(string x)
{
    ans = max(ans, (int)x.size());

    for (int i = 0; i < n; i++)
        for (int j = 0; j < str[i].size(); j++)
        {
            string sub_str = str[i].substr(0, j + 1);
            int len = sub_str.size();
            if(x.substr(x.size()-len) == sub_str)
            {
                st[i] = true;

                dfs(x + str[i].substr(j + 1));

                st[i] = false;
            }
        }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> str[i];
    string begin;
    cin >> begin;

    ans = 0;
    dfs(begin);
    cout << ans << "\n";

    return 0;
}