#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
struct dic {
    int st , ed , wz;
};

bool cmp(dic x , dic y) {
    return x.wz > y.wz || x.wz == y.wz && x.st > y.st;
}

vector<dic> x_alls , y_alls;
int n;

void merge(vector<dic> &segs) {
    vector<dic> res;
    int st = -2e9 , ed = -2e9 , ;
    for (auto seg : segs) {

    }
}

int main() {
    int x1 , x2 , y1 , y2;
    scanf("%d",&n);
    for (int i = 0 ; i < n ; i++) {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if (x1 == x2) y_alls.push_back({min(y1,y2),max(y1,y2),x1})
        else x_alls.push_back(min(x1,x2),max(x1,x2),y1);
    }
    
    sort(x_alls.begin(),x_alls.end(),cmp);
    sort(y_alls.begin(),y_alls.end(),cmp);


}