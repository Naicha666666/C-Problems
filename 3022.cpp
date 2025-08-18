#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
int n, v;
priority_queue<int> pq;
int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> v;
        pq.push(v);
    }
    while (pq.size() > 1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a ^ b);
    }
    cout << pq.top();
}
