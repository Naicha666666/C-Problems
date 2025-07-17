#include <iostream>
using namespace std;
int a[50010], l, n, m;
int check(int mid){
  int res = 0, ind = 0;
  for (int i = 1; i <= n; i ++){
    if(a[i] - a[ind] < mid) res ++;
    else ind = i;
  }
  if (l - a[ind] < mid) res ++;
  return res;
}
int main()
{
  cin >> l >> n >> m;
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  int l = 0, r = 1e9+10;
  while (l != r - 1){
    int mid = (l+r) / 2;
    if (check(mid) <= m) l = mid;
    else r = mid;
  }
  cout << l;
  return 0;
}
