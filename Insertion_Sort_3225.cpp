//Insertion Sort
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
    for (int i = 2; i <= n; ++ i){
        int val = a[i], j;
        for (j = i; j > 1 && a[j-1] > val; --j){
            a[j] = a[j-1];
        }
        a[j] = val;
    }
    for (int i = 1; i <= n; ++ i){
        cout << a[i] << " ";
    }
}
