#include <iostream>
using namespace std;
int lowbit(int x) {
    return x & -x;
}
int main() {
    int x;
    cin >> x;
    int count = 0;
    while (x) {
        x -= lowbit(x);
        count++;
    }
    cout << count;
    return 0;
}
