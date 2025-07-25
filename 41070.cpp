#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1e6 + 5;
int main() {
    int n, m;
    cin >> n;
    vector<long long> a(n), o(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        o[i] = a[i];
    }
    cin >> m;
    vector<long long> cnt(MAX, 0);
    vector<pair<long long, long long>> lr(m);
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        lr[i] = {l, r};
        cnt[l - 1]++;
        cnt[r]--;
    }
    for (int i = 1; i < MAX; ++i) {
        cnt[i] += cnt[i - 1];
    }
    nth_element(cnt.begin(), cnt.begin() + n, cnt.end(), greater<int>());
    sort(cnt.begin(), cnt.begin() + n, greater<int>());
    sort(a.begin(), a.end(), greater<int>());
    long long M = 0;
    for (int i = 0; i < n; ++i) {
        M += 1LL * a[i] * cnt[i];
    }
    vector<long long> pre(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + o[i - 1];
    }
    long long ans = 0;
    for (int i = 0; i < m; ++i) {
        long long l = lr[i].first, r = lr[i].second;
        ans += pre[r] - pre[l - 1];
    }
    cout << M - ans;
    return 0;
}
