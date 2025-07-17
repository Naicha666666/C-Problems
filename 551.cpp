#include <iostream>
using namespace std;
int a[120][120], b[120][120];
int main()
{
    int n, m;
    cin >> n >> m;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++){
        int x, y;
        cin >> x >> y;
        a[x][y] = true;
    }
    int k;
    cin >> k;
    while (k--){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (a[i][j] == true){
                    b[i][j] = true;
                    b[i-1][j] = true;
                    b[i+1][j] = true;
                    b[i][j-1] = true;
                    b[i][j+1] = true;
                }
            }
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                a[i][j] = b[i][j];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (a[i][j] == true) ans ++;
        }
    }
    cout << ans;


    return 0;
}
