#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int n, a[10000], ans;
int main()
{
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
      for (int j = 0; j < n-i; j++) {
          ans += a[i];
      }
  }
  cout << ans - a[0];
  return 0;
}
