#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll MOD = 1000000007LL;
 
ll binpow(ll a, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    
    int n = s.size();
    
    vector<ll> fact(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    
    vector<int> cnt(26, 0);
    for (char c : s) {
        cnt[c - 'a']++;
    }
    
    ll ans = fact[n];
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 1) {
            ans = ans * binpow(fact[cnt[i]], MOD - 2) % MOD;
        }
    }
    
    cout << ans;
    
    return 0;
}
