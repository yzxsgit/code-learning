#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int son[N][26], cnt[N], idx;
int n;
void insert(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if(!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
    return;
}
int find(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if(!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}
int main() {
    char str[N];
    scanf("%d", &n);
    while (n--) {
        char op[2];
        scanf("%s", op);
        cin >> str;
        if(op[0] == 'I')
            insert(str);
        else
            printf("%d\n", find(str));
    }
    return 0;
}