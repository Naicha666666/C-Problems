#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e3 + 9;
int a[N];
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++ i){
        int ind = i;
        for (int j = i; j <= n; j++){
            if (a[j] < a[ind]) ind = j;
        }
        swap(a[i], a[ind]);
    }
    for (int i = 1; i <= n; ++ i){
        cout << a[i] << " ";
    }
}
