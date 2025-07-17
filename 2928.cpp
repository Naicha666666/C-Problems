#include <iostream>
#include <algorithm>
using namespace std;
char s[10000000];
int main()
{
  int n, x;
  cin >> n >> x;
  cin >> s+1;
  sort(s+1, s+n+1);
  if (s[1] == s[n]){
    for (int i = 1; i <= n / x + (n % x?1:0); i++) cout << s[i];
  }
  else if (s[1] == s[x]){
    for (int i = x; i <= n; i++) cout << s[i];
  }
  else cout << s[x];
  return 0;
}
