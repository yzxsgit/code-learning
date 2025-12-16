#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int stk[N],tt;
void push(int x) {
    stk[++tt] = x;
    return;
}
void pop() {
    tt--;
    return;
}
bool empty() {
    return tt;
}
int query() {
    return stk[tt];
}
int main() {
    int m,x;
    scanf("%d", &m);
    string a;
    while (m--) {
        cin >> a;
        if(a == "push") {
            scanf("%d", &x);
            push(x);
        }
        else if(a == "query")
            printf("%d\n", query());
        else if(a == "pop")
            pop();
        else{
            if(empty())
                printf("NO\n");
            else
                printf("YES\n");
        }
    }
    return 0;
}