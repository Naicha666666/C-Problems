#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a[100000];
int main()
{
  cin >> n;
  cin >> m;
  for (int i = 0; i < m; i++) cin >> a[i];
  sort(a, a + m);
  int ans = 0, i = 0, j = m-1;
  while (i <= j){
    if (a[i] + a[j] <= n){
      i++;
      j--;
    }
    else{
      j--;
    }
    ans ++;
  }
  cout << ans;
  return 0;
}
