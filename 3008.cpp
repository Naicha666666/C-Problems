#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e6 + 9;
int cnt[N], pre[N];
void dfs(int dep, int st, int mul, int sum){
    if (mul > 1e6)return;
    if (dep == 4){
        cnt[mul] ++;
        return;
    }
    for (int i = st + 1; i < (dep == 3 ? sum : 1000); ++ i){
        dfs(dep + 1, i, mul*i, sum + i);
    }
}
int main() {
    dfs(1, 0, 1, 0);
    for (int i = 1; i <= 1000000; ++i) {
        pre[i] = pre[i - 1] + cnt[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << '\n';
    }
    return 0;
}
