#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
LL a[N];
LL b[N][10];
int n, m, l, r, k;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 1; j <= 5; j++)
            b[i][j] = b[i - 1][j] + pow(a[i], j);
    }
    while (m--)
    {
        cin >> l >> r >> k;
        cout << (b[r][k] - b[l - 1][k]) % MOD << "\n";
    }
    return 0;
}
