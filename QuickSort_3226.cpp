#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e5 + 9;
int a[N];
int partition(int a[], int l, int r){
    int pivot = a[r], i = l, j = r;
    while (i < j){
        while (i < j && a[i] <= pivot) i++;
        while (i < j && a[j - 1] >= pivot) j--;
        if (i < j) swap(a[i], a[j - 1]);
    }
    swap(a[i], a[r]);
    return i;
}

void QuickSort(int a[], int l, int r){
    if (l < r){
        int mid = partition(a, l, r);
        QuickSort(a, l, mid - 1);
        QuickSort(a, mid + 1, r);
    }
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    QuickSort(a, 1, n);
    for (int i = 1; i <= n; ++i){
        cout << a[i] << " ";
    }
}
