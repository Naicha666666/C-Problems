#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct Node {
    Node* next[2];
    int count;
    Node() {
        next[0] = next[1] = nullptr;
        count = 0;
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
        node->count++;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->next[bit]) node->next[bit] = new Node();
            node = node->next[bit];
            node->count++;
        }
    }
    void erase(int num) {
        Node* node = root;
        node->count--;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            node = node->next[bit];
            node->count--;
        }
    }

    int query(int num) {
        Node* node = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opp = bit ^ 1;
            if (node->next[opp] && node->next[opp]->count > 0) {
                ans |= (1 << i);
                node = node->next[opp];
            } else {
                node = node->next[bit];
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n), parent(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) cin >> parent[i];
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
    }
    Trie trie;
    for (int v : arr) trie.insert(v);
    int m = 0;
    vector<int> removed;
    for (int i = 0; i < n; i++) {
        removed.clear();
        trie.erase(arr[i]);
        removed.push_back(arr[i]);
        for (int neighbor : adj[i]) {
            trie.erase(arr[neighbor]);
            removed.push_back(arr[neighbor]);
        }
        m = max(m, trie.query(arr[i]));
        for (int val : removed) trie.insert(val);
    }
    cout << m;
    return 0;
}
