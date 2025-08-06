#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 15;
int n;
int a[N];
vector<int> v[N];
bool dfs(int cnt, int dep)
{
    if(dep == n + 1){
        return true;
    }
    for(int i = 1; i <= cnt; ++i){
        bool tag = true;
        for(const auto &j : v[i]){
            if(a[dep] % j == 0){
                tag = false;
                break;
            }
        }
        if(!tag) continue;
        v[i].push_back(a[dep]);
        if(dfs(cnt, dep + 1)) return true;
        v[i].pop_back();
    }
    return false;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j) {
            v[j].clear();
        }
        if(dfs(i, 1)){
            cout << i << '\n';
            break;
        }
    }
    return 0;
}
