#include <algorithm>
#include <cmath>

using namespace std;
long long res;
const long long p = 1e9 + 7;
long long qmi(long long a, long long b) {
    res = 1;
    while (b) {
        if (b & 1) res = (res * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}

int main() {
    long long n, m;
    cin >> n >> m;
    long long c = 1e9 + 7;
    long long phi = c;
    for (long long i = 2; i <= c / i; i++) {
        if (c%i) continue;
        phi = phi / i * (i - 1);
        while (c % i == 0) {
            c /= i;
        }
    }
    if (c > 1) phi = phi / c * (c - 1);

    long long b = 1;
    for (int i = 1; i <= m; i++) b = b * i % phi;
    cout << qmi(n, b) << "\n";
    return 0;
}
