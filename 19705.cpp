#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using ll = long long;
using namespace std;
const int N = 1000000;
ll n, k, t, a[N], b[N], e[N], ee[N];
bool f(ll m) {
    memcpy(b+1,a+1,sizeof(ll)*m);
    sort(b+1,b+m+1);
    for (ll i = 1; i <= m; ++i) e[i] = e[i-1] + b[i], ee[i] = ee[i-1] + b[i] * b[i];
    for (ll i = k; i <= m; ++i) if ((ee[i]-ee[i-k])*k - (e[i]-e[i-k])*(e[i]-e[i-k]) <= t) return 1;
    return 0;
}
int main() {
    cin >> n >> k >> t;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    t *= k * k;
    ll l = k, r = n + 1, ans = -1;
    while (l + 1 < r) {
        ll m = (l + r) >> 1;
        if (f(m)) ans = m, r = m;
        else l = m;
    }
    cout << ans;
}
