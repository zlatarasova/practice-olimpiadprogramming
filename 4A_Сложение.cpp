#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    vector<ll> diff(n + 2, 0);
    
    while (q--) {
        int l, r;
        ll v;
        cin >> l >> r >> v;
        
        diff[l] += v;
        diff[r + 1] -= v;
    }
    
    vector<ll> a(n + 1, 0);
    ll cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += diff[i];
        a[i] = cur;
    }
    
    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    
    return 0;
