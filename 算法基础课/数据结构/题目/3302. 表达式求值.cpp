#include <bits/stdc++.h>

using namespace std;
unordered_map<char, int> h = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
const int N = 1e6 + 10;
int num[N], t1, t2;
char op[N];
void eval () {
    int a = num[t1--];
    int b = num[t1--];
    char p = op[t2--];

    int r = 0;

    if(p == '+')
        r = a + b;
    else if(p == '*')
        r = a * b;
    else if(p == '-')
        r = b - a;
    else
        r = b / a;
    
    num[++t1] = r;
    
    return;
}
int main() {
    bool flag = 0;
    int res = 0;
    string str;
    cin >> str;
    for (auto i :str) {
        if (i <= '9' && i >= '0')
            res = res * 10 + i - '0', flag = 1;
        else {
            if(flag){
                num[++t1] = res;
                res = 0;
                flag = 0;
            }
            if(i == ')') {
                while (t2 && op[t2] != '(')
                    eval();
                t2--;
            }
            else if(i == '(')
                op[++t2] = i;
            else {
                while (t2 && h[op[t2]] >= h[i])
                    eval();
                op[++t2] = i;
            }
        }
    }
    if(flag)
        num[++t1] = res;
    while (t2)
        eval();
    printf("%d", num[1]);
    return 0;
}