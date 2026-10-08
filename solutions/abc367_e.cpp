#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0;i<n;i++)
using ll = long long;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n), x(n);
  rep(i,n){
    cin >> x[i];
    x[i]--;
  }
  rep(i,n)cin >> a[i];
  vector<vector<ll>> doubling(60,vector<ll>(n)); // doubling[i][j] : jから2^i回進んだものになる
  rep(i,n)doubling[0][i] = x[i]; // 一回の操作で移動する先
  rep(i,59){
    rep(j,n){
      doubling[i+1][j] = doubling[i][doubling[i][j]]; // 2^i回移動した先を2^i回移動させる
    }
  }
  vector<ll> t(n);
  iota(t.begin(), t.end(), 0);
  rep(i,60){
    if(k >> i & 1){
      rep(j,n){
        t[j] = doubling[i][t[j]];
      }
    }
  }
  rep(i,n)cout << a[t[i]] << " ";
}