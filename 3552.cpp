#include <iostream>
using namespace std;
int a[7][7];
int ans;
void dfs(int x, int y) {
    if (x == 4 && y == 0) {
        if (a[x][y] == 1) ++ans;
        return;
    }

    // AND
    a[x + 1][y] = a[x][y] & a[x][y + 1];
    if (x + y == 3) dfs(x + 1, 0);
    else dfs(x, y + 1);

    // OR
    a[x + 1][y] = a[x][y] | a[x][y + 1];
    if (x + y == 3) dfs(x + 1, 0);
    else dfs(x, y + 1);

    // XOR
    a[x + 1][y] = a[x][y] ^ a[x][y + 1];
    if (x + y == 3) dfs(x + 1, 0);
    else dfs(x, y + 1);
}
int main() {
    a[0][0] = 1;
    a[0][1] = 0;
    a[0][2] = 1;
    a[0][3] = 0;
    a[0][4] = 1;
    dfs(0, 0);
    cout << ans;
    return 0;
}
