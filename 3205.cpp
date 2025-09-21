#include <iostream>
#include <vector>
#include <numeric>
vector<bool> s(int n) {
    vector<bool> ip(n + 1, true);
    ip[0] = ip[1] = false;
    for (int p = 2; p * p <= n; ++p) {
        if (ip[p]) {
            for (int i = p * p; i <= n; i += p) {
                ip[i] = false;
            }
        }
    }
    return ip;
}

int main() {
    int n;
    cin >> n;
    vector<bool> ip = s(n);
    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (ip[i]) {
            primes.push_back(i);
        }
    }
    int count = 0;
    for (int i = 0; i < primes.size(); ++i) {
        for (int j = i + 1; j < primes.size(); ++j) {
            int diff = primes[j] - primes[i];
            if (diff > 0 && diff <= n && ip[diff]) {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}
