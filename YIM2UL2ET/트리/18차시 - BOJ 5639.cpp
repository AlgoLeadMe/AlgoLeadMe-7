#include <iostream>
using namespace std;

struct node {
    int value = -1;
    node* right = NULL;
    node* left = NULL;
};

void input(node &nd, int n) {
    if (nd.value == -1) nd.value = n;
    else if (nd.value > n) {
        if (nd.left == NULL) nd.left = new node;
        input(*nd.left, n); 
    }
    else {
        if (nd.right == NULL) nd.right = new node;
        input(*nd.right, n); 
    }
}

void output(node &nd) {
    if (nd.left != NULL) output(*nd.left);
    if (nd.right != NULL) output(*nd.right);
    cout << nd.value << '\n';
}

int main(void) {
    int n;
    node root;
    while (cin >> n) input(root, n);
    output(root);
    return 0;
}