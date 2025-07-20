#include <iostream>
using namespace std;
int calculate(int n){
    if (n == 0) return 1;
    else if (n % 2 == 0) return calculate(n / 2);
    else return calculate(n-1) + 1;
}
int main(){
    int n;
    cin >> n;
    cout << calculate(n);
    return 0;
}
