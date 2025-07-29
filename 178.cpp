#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 1e3 + 5;
char mp[N][N];
int n, scc, col[N][N];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool vis[N * N];
void dfs(int x, int y)
{
    col[x][y] = scc;
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (col[nx][ny] || mp[nx][ny] == '.')
            continue;
        dfs(nx, ny);
    }
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> mp[i] + 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (col[i][j] || mp[i][j] == '.') continue;
            scc ++;
            dfs(i, j);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (mp[i][j] == '.') continue;
            bool tag = true;
            for (int k = 0; k < 4; k++){
                int x = i + dx[k], y = j + dy[k];
                if (mp[x][y] == '.') tag = false;

            }
            if (tag){
                if (!vis[col[i][j]]) ans ++;
                vis[col[i][j]] = true;
            }
        }
    }
    cout << scc - ans;
}
//7
//.......
//.##....
//.##....
//....##.
//..####.
//....##.
//.......
