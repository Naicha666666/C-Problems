#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<long long> diff(n + 1, 0);
    for (int i = 0; i < q; ++i) {
        int l, r;
        long long k;
        cin >> l >> r >> k;
        diff[l - 1] += k;
        diff[r] -= k;
    }
    for (int i = 1; i < n; ++i) {
        diff[i] += diff[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        long long shift = diff[i] % 26;
        char c = s[i];
        char shifted = (c - 'a' + shift) % 26 + 'a';
        cout << shifted;
    }
    return 0;
}
