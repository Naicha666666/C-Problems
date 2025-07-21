#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 105;
int a[N];
int dfs(int dep){
    int res = 1;
    for (int i = 1; i <= a[dep] / 2; ++i)
    {
        a[dep + 1] = i;
        res += dfs(dep + 1);
    }
    return res;
}
int main(){
    int n;
    cin >> n;
    a[1] = n;
    cout << dfs(1) << '\n';
    return 0;
}
