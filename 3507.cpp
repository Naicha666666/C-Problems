#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using ll = long long;
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
    }
    ll ans = 0;
    for (int i = 0; i <= 20; i++) {
        ll a = 0, b = 0;
        for (int j = 0; j <= n; j++) {
            if (pre[j] & (1 << i)) b++;
            else a++;
        }
        ans += a * b * (1LL << i);
    }
    cout << ans;
    return 0;
}
