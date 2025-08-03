#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    while (n--) {
        long long a2, a3, a4, b4, b6;
        cin >> a2 >> a3 >> a4 >> b4 >> b6;
        long long m = 0;
        for (long long i = 0; i <= a4 && i <= b6; ++i) {
            long long cur = 0;
            long long b = a2;
            long long c = a3;
            long long d = a4;
            long long e = b4;
            long long f = b6;
            cur += i * 4;
            d -= i;
            f -= i;
            long long f2 = min(i, b);
            cur += f2 * 2;
            b -= f2;
            long long g = min(c / 2, f);
            cur += g * 6;
            c -= g * 2;
            f -= g;
            long long h = min(b / 3, f);
            cur += h * 6;
            b -= h * 3;
            f -= h;
            long long j = min({c, b, f});
            cur += j * 5;
            c -= j;
            b -= j;
            f -= j;
            long long k = min(d, f);
            cur += k * 4;
            d -= k;
            f -= k;
            long long l = min(b / 2, f);
            cur += l* 4;
            b -= l * 2;
            f -= l;
            long long o = min(c, f);
            cur += o * 3;
            c -= o;
            f -= o;
            long long p = min(b, f);
            cur += p * 2;
            b -= p;
            f -= p;
            long long q = min(d, e);
            cur += q * 4;
            d -= q;
            e -= q;
            long long r = min(b / 2, e);
            cur += r * 4;
            b -= r * 2;
            e -= r;
            long long s = min(c, e);
            cur += s * 3;
            c -= s;
            e -= s;
            long long t = min(b, e);
            cur += t * 2;
            b -= t;
            e -= t;
            m = max(m, cur);
        }
        cout << m << endl;
    }
    return 0;
}
