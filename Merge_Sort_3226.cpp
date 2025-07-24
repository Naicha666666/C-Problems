#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e5 + 9;
int a[N], b[N];
void Merge(int a[], int l, int r){
    if (l == r) return;
    int mid = (l+r)/2;
    Merge(a, l, mid);
    Merge(a, mid + 1, r);
    int pl = l, pr = mid + 1, pb = l;
    while (pl <= mid || pr <= r){
        if (pl > mid) b[pb ++] = a[pr++];
        else if (pr > r)b[pb ++] = a[pl++];
        else{
            if (a[pl] < a[pr]) b[pb++] = a[pl ++];
            else b[pb++] = a[pr++];
        }
    }
    for (int i = l; i <= r; i ++){
        a[i] = b[i];
    }
}
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    Merge(a, 1, n);
    for (int i = 1; i <= n; ++ i){
        cout << a[i] << " ";
    }
}
