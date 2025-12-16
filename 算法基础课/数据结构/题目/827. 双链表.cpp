#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
struct List{
    int val, l, r;
}a[N];

int m, idx;
void init() {
    a[0].r = 1, a[1].l = 0;
    idx = 2;
    return;
}

void add(int k ,int x) {
    a[idx].val = x;
    a[idx].l = k;
    a[idx].r = a[k].r;
    a[a[k].r].l = idx;
    a[k].r = idx++;
    return;
}
void remove(int k) {
    a[a[k].l].r = a[k].r;
    a[a[k].r].l = a[k].l;
    return;
}

int main(){
    init();
    int k, x;
    string c;
    scanf("%d", &m);
    while (m--) {
        cin >> c;
        if(c == "R"){
            scanf("%d", &x);
            add(a[1].l, x);
        }
        else if (c == "L" ){
            scanf("%d", &x);
            add(0, x);
        }
        else if (c == "D" ){
            scanf("%d", &k);
            remove(k + 1);
        }
        else if (c == "IL" ){
            scanf("%d %d", &k, &x);
            add(a[k + 1].l, x);
        }
        else if(c == "IR" ){
            scanf("%d %d", &k, &x);
            add(k + 1, x);
        }
    }
    for (int i = a[0].r; i != 1; i = a[i].r)
        printf("%d ",a[i].val);
    return 0;
}