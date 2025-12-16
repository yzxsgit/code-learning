#include<iostream>
#include<unordered_map>

using namespace std;

char str[100];

unordered_map<long long,string> hash_map;

string num_to_code(long long num)
{
    string res = "";
    while (num)
    {
        int t = num % 38;
        if(t == 0 && res != "")
        {
            res = " " + res;
        }
        else if (t >= 1 && t <= 10)
        {
            char add = t - 1 + '0';
            res = add + res;
        }
        else if (t >= 11 && t <= 36)
        {
            char add = t - 11 + 'A';
            res = add + res;
        }
        else
        {
            res = '_' + res;
        }
        num /= 38;
    }

    return res;
}

long long str_to_num(int l, int r)
{
    long long res = 0;
    for (int i = l; i < r; i++)
        res = res * 2 + str[i] - '0';
    return res;
}

void solve()
{
    scanf("%s", str);
    if(str[0] == '1')
    {
        long long code_num = str_to_num(1, 1 + 58);
        cout << code_num << endl;
        long long hash_value_num = str_to_num(1 + 58, 1 + 58 + 12);
        string code = num_to_code(code_num);
        cout << code << endl;
    }
    else
    {

    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}