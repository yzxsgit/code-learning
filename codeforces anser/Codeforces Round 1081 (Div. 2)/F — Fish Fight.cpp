#include <bits/stdc++.h>
using namespace std;

// using namespace std;
using ll = long long;
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define int long long
#define vt vector
const ll mod = 1000000007;

int bexpo(int b, int e) {
    int ans = 1;
    while(e) {
        if(e&1) ans=ans*b%mod;
        e>>=1;
        b=b*b%mod;
    }
    return ans;
}
signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n,x,y;
        cin >> n >> x >> y;
        x--;
        y--;
        vt<int> a(n), b(n);
        F0R(i, n) cin >> a[i];
        F0R(i, n) cin >> b[i];
        if(x>y) {
            reverse(begin(a),end(a));
            reverse(begin(b),end(b));
            x=n-x-1;
            y=n-y-1;
        }
        b[x]=b[y]=0;
        vt<int> pb(n+1);
        F0R(i, n) pb[i+1]=pb[i]+b[i];
        vt<vt<int>> adp(n, vt<int>(n));
        adp[x][x]=1;
        FOR(d, 1, n) {
            FOR(r, d, n) {
                int l = r-d;
                if(x<l || x>r) continue;
                if(y>=l && y<=r) continue;
                int size_without_r = a[x]+pb[r]-pb[l];
                if(size_without_r<a[r]) continue;
                if(l!=0 && size_without_r>=a[l-1]) {
                    adp[l][r]+=adp[l][r-1]*bexpo(2, mod-2);
                } else {
                    adp[l][r]+=adp[l][r-1];
                }
                adp[l][r]%=mod;
                int size_without_l = a[x]+pb[r+1]-pb[l+1];
                if(size_without_l<a[l]) continue;
 
                if(r!=n-1 && size_without_l>=a[r+1]) {
                    adp[l][r]+=adp[l+1][r]*bexpo(2, mod-2);
                } else {
                    adp[l][r]+=adp[l+1][r];
                }
                adp[l][r]%=mod;
            }
        }
        vt<vt<int>> bdp(n, vt<int>(n));
        bdp[y][y]=1;
        FOR(d, 1, n) {
            FOR(r, d, n) {
                int l = r-d;
                if(y<l || y>r) continue;
                if(x>=l && x<=r) continue;
                int size_without_r = a[y]+pb[r]-pb[l];
                if(size_without_r<a[r]) continue;
                if(l!=0 && size_without_r>=a[l-1]) {
                    bdp[l][r]+=bdp[l][r-1]*bexpo(2, mod-2);
                } else {
                    bdp[l][r]+=bdp[l][r-1];
                }
                bdp[l][r]%=mod;
                int size_without_l = a[y]+pb[r+1]-pb[l+1];
                if(size_without_l<a[l]) continue;
                if(r!=n-1 && size_without_l>=a[r+1]) {
                    bdp[l][r]+=bdp[l+1][r]*bexpo(2, mod-2);
                } else {
                    bdp[l][r]+=bdp[l+1][r];
                }
                bdp[l][r]%=mod;
            }
        }
        /*
        when we have Bob stuck at the interval [l,r] and Alice has not seen Bob yet, then Bob loses
        take sum of adp over fixed size and max r
        */
 
        vt<vt<int>> asum(n, vt<int>(n));
        F0R(l, n) FOR(r, l, n) {
            asum[r-l][r]=adp[l][r];
        }
        FOR(diff, 0, n) {
            FOR(mxr, 1, n) {
                asum[diff][mxr]+=asum[diff][mxr-1];
                asum[diff][mxr]%=mod;
            }
        }
        int ans = 0;
 
        FOR(l, 2, n) {
            FOR(r, l, n) {
                int bsz = a[y]+pb[r+1]-pb[l];
                if(l!=0 && bsz>=a[l-1]) continue;
                if(r!=n-1 && bsz>=a[r+1]) continue;
                ans+=asum[r-l+1][l-2]*bdp[l][r];
                ans%=mod;
            }
        }

        vt<vt<int>> dp(n, vt<int>(n));
        if(y==x+1) {
            dp[x][y]=1;
        }
        FOR(diff, y-x, n) {
            FOR(r, y, n) {
                int l = r-diff;
                if(x<l || x>r || y<l || y>r || l<0 || r>=n) continue;
                int aend = (l+r)/2;
                if(l%2==r%2) {
                    /*
                    last move is alice
                    so either broke the wall (eats aend)
                    or it was dp[l+1][r] and ate l
                    */
                    int asz = a[x]+pb[aend+1]-pb[l+1], bsz = a[y]+pb[r+1]-pb[aend+1];
                    if(asz>=a[l]) {
                        if(asz>=bsz) {
                            dp[l][r]+=dp[l+1][r]*bexpo(2, mod-2);
                            dp[l][r]%=mod;
                        } else {
                            dp[l][r]+=dp[l+1][r];
                            dp[l][r]%=mod;
                        }
                    }
                    if(aend!=0) {
                        int chance = adp[l][aend-1]*bdp[aend+1][r]%mod;
                        asz = a[x]+pb[aend]-pb[l];
                        if(asz>=a[aend]) {
                            if(l!=0 && asz>=a[l-1]) {
                                dp[l][r]+=chance*bexpo(2, mod-2);
                                dp[l][r]%=mod;
                            } else {
                                dp[l][r]+=chance;
                                dp[l][r]%=mod;
                            }
                        }
                    }
                } else {
                    int asz = a[x]+pb[aend+1]-pb[l], bsz = a[y]+pb[r]-pb[aend+1];
                    if(bsz>=a[r]) {
                        if(bsz>=asz) {
                            dp[l][r]+=dp[l][r-1]*bexpo(2, mod-2);
                            dp[l][r]%=mod;
                        } else {
                            dp[l][r]+=dp[l][r-1];
                            dp[l][r]%=mod;
                        }
                    }
                    if(aend+2<n) {
                        int chance = adp[l][aend]*bdp[aend+2][r]%mod;
                        bsz = a[y]+pb[r+1]-pb[aend+2];
                        if(bsz>=a[aend+1]) {
                            if(r!=n-1 && bsz>=a[r+1]) {
                                dp[l][r]+=chance*bexpo(2, mod-2);
                                dp[l][r]%=mod;
                            } else {
                                dp[l][r]+=chance;
                                dp[l][r]%=mod;
                            }
                        }
                    }
                }
                int asz = a[x]+pb[aend+1]-pb[l], bsz = a[y]+pb[r+1]-pb[aend+1];
                if(l%2==r%2) {
                    //bob's turn
                    if(bsz<asz) {
                        if(r==n-1 || a[r+1]>bsz) {
                            ans+=dp[l][r];
                            ans%=mod;
                        }
                    }
                } else {
                    if(asz>=bsz) {
                        if(l!=0 && asz>=a[l-1]) {
                            ans+=bexpo(2, mod-2)*dp[l][r];
                            ans%=mod;
                        } else {
                            ans+=dp[l][r];
                            ans%=mod;
                        }
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}