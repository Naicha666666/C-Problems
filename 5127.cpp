#include <iostream>
#include <string>
#include <vector>


using namespace std;
bool iscomp(char c0, char c1, char c2, char c3) {
    if (c0 == c1 && c1 == c2 && c0 != c3) {
        return true;
    }
    if (c0 == c1 && c1 == c3 && c0 != c2) {
        return true;
    }
    if (c0 == c2 && c2 == c3 && c0 != c1) {
        return true;
    }
    if (c1 == c2 && c2 == c3 && c1 != c0) {
        return true;
    }
    return false;
}


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        if (iscomp(a[0], a[1], a[2], a[3])) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
