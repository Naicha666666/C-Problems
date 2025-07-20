#include <iostream>
using namespace std;
int s(int n, int base) {
    int sum = 0;
    while (n > 0) {
        sum += n % base;
        n /= base;
    }
    return sum;
}
int main() {
    int count = 0;
    for (int i = 1; i <= 2024; ++i) {
        if (s(i, 2) == s(i, 4)) {
            count++;
        }
    }
    cout << count;
    return 0;
}
