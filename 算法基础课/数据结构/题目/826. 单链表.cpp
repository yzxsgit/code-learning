#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;
struct List {
    int val, next;

} a[N];
int m, head , idx ;
void init() {
    head = -1;
    idx = 0;
}

void add_head(int x) {
    a[idx].val = x;
    a[idx].next = head;
    head = idx++;
    return;
}

void add(int k ,int x) {
    a[idx].val = x;
    a[idx].next = a[k].next;
    a[k].next = idx++;
    return;
}


void remove(int k) {
    a[k].next = a[a[k].next].next;
    return;
}
int main() {
    scanf("%d", &m);
    init();
    char op;
    int x, k;
    while (m--) {
        cin >> op;
        if(op == 'H') {
            scanf("%d", &x);
            add_head(x);
        }
        if(op == 'I') {
            scanf("%d%d", &k, &x);
            add(k - 1, x);
        }
        if(op == 'D') {
            scanf("%d", &k);
            if (!k)
                head = a[head].next;
            else
                remove(k - 1);
        }
    }
    for (int i = head; i != -1;i = a[i].next)
        printf("%d ", a[i].val);

    return 0;
}