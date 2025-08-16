#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
//#include
using namespace std;
using ll = long long;
int main(){
    int n, m, N = 3e5+5, ans = 0;
    int dif[N], pre[N];
    vector<pair<int, int>> v;
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
        dif[a] ++;
        dif[b+1] --;
    }
    for (int i = 1; i <= n; i++){
        dif[i] += dif[i-1];
        pre[i] += pre[i-1] + (dif[i] <= 1);
        if (dif[i] == 0) ans ++;
    }
    for (int i = 0; i < m; i++){
        cout << pre[v[i].second] - pre[v[i].first-1] + ans << endl;
    }
}
