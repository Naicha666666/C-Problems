#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
using ll = long long;


int n, m, k;
int a, b, c, d;
vector<vector<int>> h;
vector<vector<int>> dp;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


bool dfs(int x, int y, int used) {
   if (x == c && y == d) return true;
   if (used >= dp[x][y]) return false;
   dp[x][y] = used;
   for (int dir = 0; dir < 4; dir++) {
       int nx = x + dx[dir], ny = y + dy[dir];
       if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
       int nw = used;
       if (h[nx][ny] > h[x][y]) {
           nw += h[nx][ny] - h[x][y];
       }
       if (nw <= k) {
           if (dfs(nx, ny, nw)) return true;
       }
   }
   return false;
}


int main() {
   cin >> n >> m >> k;
   cin >> a >> b >> c >> d;
   a--; b--; c--; d--;
   h.resize(n, vector<int>(m));
   dp.resize(n, vector<int>(m, INT_MAX));
   for (int i = 0; i < n; i++)
       for (int j = 0; j < m; j++)
           cin >> h[i][j];
   cout << (dfs(a, b, 0) ? "Yes" : "No");
   return 0;
}
