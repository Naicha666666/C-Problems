#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int M = 200005;
const int A = 26;
int nex[M][A];
int cnt[M];
int idx;
void init() {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < A; ++j) {
            nex[i][j] = 0;
        }
        cnt[i] = 0;
    }
    idx = 1;
}
void insert(const string& s) {
    int p = 1;
    for (char ch : s) {
        int c = ch - 'a';
        if (nex[p][c] == 0) {
            nex[p][c] = ++idx;
        }
        p = nex[p][c];
    }
    cnt[p]++;
}
bool check(const string& s) {
    int p = 1;
    for (char ch : s) {
        int c = ch - 'a';
        if (nex[p][c] == 0) {
            return false;
        }
        p = nex[p][c];
    }
    return true;
}
int main() {
    int n, m;
    cin >> n >> m;
    init();
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        insert(s);
    }
    for (int i = 0; i < m; ++i) {
        string t;
        cin >> t;
        if (check(t)) {
            cout << "Y";
        } else {
            cout << "N";
        }
    }

    return 0;
}
