#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool f(int x){
    while(x){
        int y = x % 10;
        if (y == 2 || y == 0 || y == 1 || y == 9){
            return true;
        }
        x/=10;
    }
    return false;
}
int main() {
    int t, ans;
    cin >> t;
    ans = 0;
    for (int i = 1; i <= t; i++){
        if(f(i)) {
            ans += i;
        }
    }
    cout << ans;
    return 0;
}
