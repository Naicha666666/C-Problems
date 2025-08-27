#include <iostream>
using namespace std;
typedef long long ll;
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
ll getabs(ll x) {
    return x < 0 ? -x : x;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        ll a, b, m;
        cin >> a >> b >> m;
        ll x, y, d = exgcd(getabs(a), getabs(m), x, y);
        if(b % d) {
            cout << -1 << '\n';
        } else {
            x *= (a < 0 ? -1 : 1) * (b / d);
            x = (x % (m / d) + (m / d)) % (m / d);
            cout << x << '\n';
        }
    }
    return 0;
}
