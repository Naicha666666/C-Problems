#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
//#include
using namespace std;
using ll = long long;
const int N = 1e5 + 3;
int c[N];
long long pre[N];
int n, q;
int main(){
    cin >> n >> q;
    for (int i = 1; i <= n; i ++)cin >> c[i];
    sort(c + 1, c + n +1);
    for (int i = 1; i <= n; i ++) pre[i] = pre[i - 1] + c[i];
    while (q--){
        int k, m;
        cin >> k >> m;
        int l = 0, r = m+1;
        while (l + 1 != r){
            int mid = (l+r)/2;
            if (c[mid] < 2*k-c[n-m+mid]) l = mid;
            else r = mid;
        }
        long long res = pre[l] + 2 * k * (m - l) - (pre[n]- pre[n-m+l]);
        cout << res;
    }
}
