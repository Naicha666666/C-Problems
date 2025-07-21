// This method TLE (O(N^2*sqrt(N))) 
//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//int fact(int x) {
//    if (x == 0) return 0;
//    int count = 0;
//    int s = sqrt(x);
//    for (int i = 1; i <= s; ++i) {
//        if (x % i == 0) {
//            if (i * i == x) {
//                count += 1;
//            } else {
//                count += 2;
//            }
//        }
//    }
//    return count;
//}
//int main() {
//    int n;
//    cin >> n;
//    vector<int> a(n+1);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//    int ans = 0;
//    for (int i = 0; i < n; ++i) {
//        int x = 0;
//        for (int j = i; j < n; ++j) {
//            x ^= a[j];
//            int f = fact(x);
//            if (f % 2 == 0 && f != 0) {
//                ans++;
////                cout << i << " " << j << "\n";
//            }
//        }
//    }
//    cout << ans << endl;
//    return 0;
//}


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e5 + 9;
int a[N], prexor[N], cnt[N];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        prexor[i] = prexor[i - 1] ^ a[i];
    cnt[0] = 1;
    int ans = n * (n + 1) / 2;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 200; j++) {
            int sq = j * j;
            ans -= cnt[prexor[i] ^ sq];
        }
        cnt[prexor[i]]++;
    }
    cout << ans;
    return 0;
}
