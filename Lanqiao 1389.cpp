#include <iostream>
using namespace std;
int main(){
    int data[200];
    for (int i=0; i<200; i++) {
      data[i] = 4*i+6;
    }
    int n;
    cin >> n;
    int l = 0, r = 200, mid;
    while (l != r -1){
      mid = (l+r) / 2;
      if (data[mid] >= n) r = mid;
      else l = mid;
    }
    cout << r;
    return 0;
}
