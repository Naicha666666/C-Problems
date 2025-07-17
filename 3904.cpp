#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool iscomp(char a, char b){
    if (a == 'A' && b == 'T') return true;
    else if (a == 'C' && b == 'G') return true;
    else if (a == 'G' && b == 'C') return true;
    else if (a == 'T' && b == 'A') return true;
    else return false;
}
int main() {
    int n, ans;
    ans = 0;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<bool> fixed(n, false);
    vector<int> m;
    for (int i = 0; i < n; ++i) {
        if (!iscomp(a[i], b[i])) {
            m.push_back(i);
        }
    }
    for (size_t i = 0; i < m.size(); ++i) {
        int x = m[i];
        if (fixed[x]) {
            continue;
        }
        for (size_t j = i + 1; j < m.size(); ++j) {
            int y = m[j];
            if (fixed[y]) {
                continue;
            }
            if (iscomp(a[x], b[y]) && iscomp(a[y], b[x])) {
                ans++;
                fixed[x] = true;
                fixed[y] = true;
                break;
            }
        }
    }
    for (int z : m) {
        if (!fixed[z]) {
            ans++;
            fixed[z] = true;
        }
    }
    cout << ans;
    return 0;
}
//5
//ACGTG
//ACGTC


//6
//ACTGAT
//CTAGAT
