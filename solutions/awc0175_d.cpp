#include <bits/stdc++.h>
using namespace std;
#include<atcoder/all>
using namespace atcoder; 
#define rep(i,n) for(long long i=0;i<n;i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
using ll = long long;

// k分割するのが最適
// 最大値が幾つになるかで二分探索
// 貪欲
int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll s = 0;
    rep(i,n)cin >> a[i], s = max(s, a[i]);

    ll l = s-1, r = 1e18;
    while(r-l > 1){
        ll mid = (l+r)/2;
        ll cnt = 0;
        ll tmp = 0;
        rep(i,n){
            if(tmp + a[i] <= mid)tmp += a[i];
            else{
                tmp = a[i];
                cnt++;
            }
        }
        if(cnt >= k)l = mid;
        else r = mid;
    }
    cout << r;
    return 0;
}