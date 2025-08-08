#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e5 + 9;
int cnt[N], pre[N], n;
void dfs(int dep, int st, int mul, int sum){
    if (mul > 1e5)return;
    if (dep == n+1){
        cnt[mul] ++;
        return;
    }
    int up = pow(1e5/mul, 1.0 / (n-dep+1)) + 3;
    for (int i = st + 1; i < (dep == n ? min(sum, up) : up); ++ i){
        dfs(dep + 1, i, mul*i, sum + i);
    }
}
int main() {
    int q;
    cin >> q >> n;
    dfs(1, 0, 1, 0);
    for (int i = 1; i <= 1e5; ++i) {
        pre[i] = pre[i - 1] + cnt[i];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << '\n';
    }
    return 0;
}
