#include <iostream>
using namespace std;
using ll = long long;
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if(b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll getabs(ll x){return x < 0 ? -x : x;}

int main()
{
    ll _x, _y, m, n, l;cin >> _x >> _y >> m >> n >> l;
    ll a = m - n, b = l, c = _y - _x;
    ll x, y, d = exgcd(getabs(a), getabs(b), x, y);
    if(c % d)
    {
        cout << "impossible\n";
    }
    else
    {
        x *= (a < 0 ? -1 : 1) * (c / d);
        x = (x % (b / d) + (b / d)) % (b / d);
        cout << x << '\n';
    }
    return 0;
}
