#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;
int q[N], head = 0, tail = 0;
void push(int x) {
    q[tail++] = x;
    return;
}
void pop() {
    head++;
}
bool empty() {
    return tail == head;
}
int query() {
    return q[head];
}
int main() {
    int n, x;
    string op;
    scanf("%d", &n);
    while (n--) {
        cin >> op;
        if (op == "push"){
            scanf("%d", &x);
            push(x);
        }
        else if(op == "empty"){
            if(!empty())
                printf("NO\n");
            else
                printf("YES\n");
        }
        else if (op == "query")
            printf("%d\n", query());
        else
            pop();
    }
    return 0;
}