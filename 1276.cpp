#include<bits/stdc++.h>
using namespace std;
long long a[500000];
long long diff[500000];
int main()
{ 
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        diff[i] = a[i] - a[i-1];
    }
    while(m--){
      int x, y, z;
      cin >> x >> y >> z;
      diff[x] += z; 
      diff[y+1] -= z;
    }
    for(int i = 1; i <= n; i++){
      a[i] = diff[i] + a[i-1];
    }
    for(int i = 1; i <= n; i++){
        if(a[i] >= 0) cout << a[i] << " ";
        else cout << "0" << " ";
    }
    return 0;
 }
