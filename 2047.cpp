#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 1e6 + 9;
int nex[N];
char s[N], p[N];
int main() {
    cin >> s + 1; int n = strlen(s + 1);
    cin >> p + 1; int m = strlen(p + 1);
    nex[0] = nex[1] = 0;
    for (int i = 2, j = 0; i <= m; i++) {
        while (j && p[i] != p[j+1]) j = nex[j];
        if (p[i] == p[j+1]) j++;
        nex[i] = j;
    }

    int ans = 0;
    for (int i = 1, j = 0; i <= n; i++) {
        while (j && s[i] != p[j+1]) j = nex[j];
        if (s[i] == p[j + 1]) j++;
        if (j == m) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
