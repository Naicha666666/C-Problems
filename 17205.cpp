#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;
struct Node {
    Node* next[2];
    Node() {
        next[0] = next[1] = nullptr;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->next[bit])
                node->next[bit] = new Node();
            node = node->next[bit];
        }
    }
    int query(int num) {
        Node* node = root;
        int result = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite = bit ^ 1;
            if (node->next[opposite]) {
                result |= (1 << i);
                node = node->next[opposite];
            } else {
                node = node->next[bit];
            }
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    Trie trie;
    trie.insert(0);
    int pre = 0, m = 0;
    for (int num : arr) {
        pre ^= num;
        m = max(m, trie.query(pre));
        trie.insert(pre);
    }
    cout << m;
    return 0;
}
