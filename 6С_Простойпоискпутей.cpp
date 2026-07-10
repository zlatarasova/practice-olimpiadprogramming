#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> g;
vector<int> p;
vector<bool> used;
int n, m, u, v;
bool ok = false;
 
void dfs(int x) {
    if (ok) return;
    used[x] = true;
    if (x == v) { ok = true; return; }
    for (int y : g[x]) {
        if (!used[y]) {
            p[y] = x;
            dfs(y);
            if (ok) return;
        }
    }
}
 
int main() {
    cin >> n >> m >> u >> v;
    g.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    p.assign(n + 1, -1);
    used.assign(n + 1, false);
    
    dfs(u);
    
    if (!ok) { cout << -1; return 0; }
    
    vector<int> path;
    for (int x = v; x != -1; x = p[x]) path.push_back(x);
    reverse(path.begin(), path.end());
    
    for (int x : path) cout << x << ' ';
