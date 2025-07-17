#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
int c_i(char c) {
    if (isdigit(c)) return c - '0';
    return c - 'A' + 10;
}
char i_c(int v) {
    if (v < 10) return '0' + v;
    return 'A' + (v - 10);
}
long long b_d(const string& num, int a) {
    long long result = 0;
    for (char c : num) {
        result = result * a + c_i(c);
    }
    return result;
}
string d_b(long long num, int b) {
    if (num == 0) return "0";
    string result;
    while (num > 0) {
        result += i_c(num % b);
        num /= b;
    }
    reverse(result.begin(), result.end());
    return result;
}


int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    string num; 
    int a, b;
    cin >> a >> b;
    cin >> num;
    long long d = b_d(num, a);
    cout << d_b(d, b) << endl;
  }
  return 0;
}

