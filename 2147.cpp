#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using ll = long long;
using namespace std;
const int mlie = 1e6 + 5, nhang = 85;
int a[nhang][mlie];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    int lim;
    cin >> lim;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = i; k <= n; k++) {
                for (int l = j; l <= m; l++) {
                    int mn = a[i][j], mx = a[i][j];
                    int area = 0;
                    for (int o = i; o <= k; o++) {
                        for (int p = j; p <= l; p++) {
                            mn = min(mn, a[o][p]);
                            mx = max(mx, a[o][p]);
                            area++;
                        }
                    }
                    if (mx - mn <= lim && area > ans) {
                        ans = area;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
