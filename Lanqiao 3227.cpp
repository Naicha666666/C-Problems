#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
map<int, int> mp;
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++){
        int x;
        cin >> x;
        mp[x] ++;
    }
    for (const auto &[x, y] : mp ){
        if (2*y > m*n){
            cout << x;
        }
    }
    return 0;
}
