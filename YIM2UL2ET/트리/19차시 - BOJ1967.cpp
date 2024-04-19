#include <iostream>
#include <vector>
using namespace std;

int maxValue, maxNode;

struct node {
    bool visit = false;
    vector <pair <int, int>> link;
};

void dfs(vector <node> &tree, int nd, int val) {
    tree[nd-1].visit = true;
    if (val > maxValue) maxValue = val, maxNode = nd;
    for (auto i : tree[nd-1].link) {
        if (!tree[i.first-1].visit) dfs(tree, i.first, val+i.second);
    }
}

int main(void) {
    int n, parent, child, value;

    cin >> n;
    vector <node> tree(n);

    for (int i = 0; i < n-1; i++) {
        cin >> parent >> child >> value;
        tree[parent-1].link.push_back({child, value});
        tree[child-1].link.push_back({parent, value});
    }
    
    auto copyTree = tree;
    dfs(copyTree, 1, 0);
    dfs(tree, maxNode, 0);
    cout << maxValue;
    return 0;
}