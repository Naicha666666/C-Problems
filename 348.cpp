#include<bits/stdc++.h>
using namespace std;
int a[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main(){
  int n, m;
  cin >> n >> m;
  int ans;
  for (int i = 1; i <= 12; i ++){
    for (int j = 1; j <= a[i]; j++){
      int y;
      y = (j%10) * 1000 + (j/10) * 100 + (i%10) * 10 + (i/10);
      int sum;
      sum = 10000 * y + 100 * i + j;
      if (sum < n || sum > m) continue;
      else ans ++;
    }
  }
  cout << ans;
  return 0;
}
