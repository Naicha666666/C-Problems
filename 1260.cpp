#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <numeric>
using namespace std;
//int gcd(int a, int b){
//    return b == 0 ? a : gcd(b, a % b);
//}
int main(){
    int n;
    cin >> n;
    while (n--){
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
}
