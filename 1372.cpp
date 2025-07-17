#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  int ans, n, m, a[100005], sum;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sum = 0;
  ans = 1e9;
  for (int i = 1, j = 0; i <= n; i ++){
    while (sum < m && j <= n) j ++, sum += a[j];
    if (sum >= m)
    ans = min(ans, j-i+1);
    sum -= a[i];
  }
  if (ans == 1e9){
    cout << 0;
  }
  else cout << ans;
  return 0;
} 
