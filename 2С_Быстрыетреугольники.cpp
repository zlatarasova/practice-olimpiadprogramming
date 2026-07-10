#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    sort(a.begin(), a.end());
 
    long long ans = 0;
 
    for (int i = 0; i < n - 2; i++) {
        if (a[i] == 0) continue;
        int k = i + 2;
        for (int j = i + 1; j < n - 1; j++) {
            while (k < n && a[i] + a[j] > a[k]) {
                k++;
            }
            ans += k - j - 1;
        }
    }
 
    cout << ans;
 
    return 0;
}
