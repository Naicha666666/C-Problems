#include <iostream>
using namespace std;
const int N = 1e5 + 9;
int dfn[N], a[N], idx, mindfn;
int dfs(int x)
{
    idx ++;
    dfn[x] = idx;
    if (dfn[a[x]])
    {
        if (dfn[a[x]] >= mindfn)
            return dfn[x] - dfn[a[x]] + 1;
        return 0;
    }
    return dfs(a[x]);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!dfn[i])
        {
            mindfn = idx + 1;
            ans = max(ans, dfs(i));
        }
    }
    cout << ans;
    return 0;
}
