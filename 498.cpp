#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int p[13] = {0, 10100101, 11111111, 20200202, 21211212, 30300303, 40400404, 50500505, 60600606, 70700707, 80800808, 90900909};
vector<int> v;
int main(){
  string s;
  cin >> s;
  for (int i = 1; i <= 12; i++){
    for (int j = 1; j <= month[i]; j++){
      int y;
      y = i * 100 + j;
      string x, z;
      x = to_string(y);
      if (x.length() == 3) x = "0" + x;
      z = to_string(y);
      if (z.length() == 3) z = "0" + z;
      reverse(x.begin(), x.end());
      string full = x + z;
      int num;
      num = stoi(full);
      if (num >= 10000000) v.push_back(num);
    }
  }
//  for (int i = 1; i <= 365; i++){
//        cout << v[i] << "\n";
//    }
  int n = stoi(s);
  sort(v.begin(), v.end());
  for (int i = 0; i <= 1000; i++){
      if (v[i] > n) {
          cout << v[i] << "\n";
          break;
      }
  }
  for (int i = 0; i <= 100; i++){
    if (p[i] > n) {
        cout << p[i] << "\n";
        break;
        }
    }
}
