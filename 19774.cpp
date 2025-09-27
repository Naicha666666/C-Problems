#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <numeric>
using namespace std;
using ll = long long;
vector<vector<ll>> v;
int main(){
    ll n, m, c;
    cin >> n >> m >> c;
    v.resize(n+1);
    for (int i = 0; i <= n; i ++){
        v[i].resize(m+1);
        v[i][0] = 1;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            v[i][j] = (v[i-1][j-1] + v[i-1][j]) % c;
        }
    }
    cout << v[n][m];
}
