#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '1' && s[i + 1] == '0') {
            pre[i + 1] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        pre[i] += pre[i - 1];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        cout << pre[r - 1] - pre[l - 1] << '\n';
    }
    return 0;
}
