#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a, b, c;
bool f(int x){
    return x % a != 0 && x % b != 0 && x % c != 0;
}
int main() {
    int t, ans;
    cin >> t;
    cin >> a >> b >> c;
    ans = 0;
    for (int i = 1; i <= t; i++){
        if(f(i)) {
            ans ++;
        }
    }
    cout << ans;
    return 0;
}
