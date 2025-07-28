#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int vis[15][15], n, ans;
void dfs(int dep){
    if (dep == n+1){
        ans ++;
        return;
    }
    for (int i = 1; i <= n; i++){
        if (vis[dep][i]) continue;
        for (int _i = 1; _i <= n; _i++) vis[_i][i] ++;
        for (int _i = dep, _j = i; _i >= 1 && _j >= 1; _i--, _j--) vis[_i][_j] ++;
        for (int _i = dep, _j = i; _i <= n && _j >= 1; _i++, _j--) vis[_i][_j] ++;
        for (int _i = dep, _j = i; _i >= 1 && _j <= n; _i--, _j++) vis[_i][_j] ++;
        for (int _i = dep, _j = i; _i <= n && _j <= n; _i++, _j++) vis[_i][_j] ++;
        dfs(dep+1);
        for (int _i = 1; _i <= n; _i++) vis[_i][i] --;
        for (int _i = dep, _j = i; _i >= 1 && _j >= 1; _i--, _j--) vis[_i][_j] --;
        for (int _i = dep, _j = i; _i <= n && _j >= 1; _i++, _j--) vis[_i][_j] --;
        for (int _i = dep, _j = i; _i >= 1 && _j <= n; _i--, _j++) vis[_i][_j] --;
        for (int _i = dep, _j = i; _i <= n && _j <= n; _i++, _j++) vis[_i][_j] --;

    }
}
int main(){
    cin >> n;
    dfs(1);
    cout << ans;
}
