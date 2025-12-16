#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
typedef pair<int,int> PII;

vector<PII> segs;


void merge(vector<PII> &segs) {
    vector<PII> res;
    int st = -2e9 , ed = -2e9;
    for (auto seg : segs) {
        if (ed < seg.first) {
            if(st != -2e9) res.push_back({st,ed});
            st = seg.first;
            ed = seg.second;
        }
        else ed = max(ed , seg.second);
    }
    if(st != -2e9) res.push_back({st,ed});

    segs = res;
}

int main() {
    int n , l , r;
    scanf("%d",&n);
    for (int i = 0 ; i < n ; i++) {
        scanf("%d%d",&l,&r);
        segs.push_back({l,r});
    }

    sort(segs.begin(),segs.end());
    
    merge(segs);

    printf("%d",segs.size());
    
    return 0;
}