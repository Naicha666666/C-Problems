#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using ll = long long;
using namespace std;
int main() {
   int n;
   cin >> n;
   vector<int> p(n);
   for (int i = 0; i < n; i++) {
       cin >> p[i];
   }
   for (int level = n; level > 1; level--) {
       for (int i = 0; i < level - 1; i++) {
           p[i] = p[i] ^ p[i + 1];
       }
   }
   cout << p[0] << endl;
   return 0;
}
