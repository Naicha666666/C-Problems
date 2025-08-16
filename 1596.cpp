#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
struct C {
    int p, e, q;
};
bool cmp(const C &x, const C &y) {
    return x.e > y.e;
}
struct Node {
    int p, e, q;
    bool operator<(const Node &other) const {
        return p > other.p;
    }
};
int main() {
    int x, n;
    cin >> x >> n;
    vector<C> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i].p >> c[i].e >> c[i].q;
    }
    sort(c.begin(), c.end(), cmp);
    priority_queue<Node> pq;
    int idx = 0;
    ll cost = 0;
    for (int day = x; day >= 1; day--) {
        while (idx < n && c[idx].e >= day) {
            pq.push({c[idx].p, c[idx].e, c[idx].q});
            idx++;
        }
        if (pq.empty()) {
            cout << -1;
            return 0;
        }
        auto cur = pq.top(); pq.pop();
        cost += cur.p;
        cur.q--;
        if (cur.q > 0) pq.push(cur);
    }
    cout << cost;
    return 0;
}
