#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    int key;
    int data = 0;
    ListNode* left = nullptr;
    ListNode* right = nullptr;
    ListNode* p = nullptr;

    ListNode(int key, int data=0): key(key), data(data) {}
};

ListNode* my_search (ListNode* root, int nkey) {
    if (root == nullptr || nkey == root->key)
        return root;
    if (nkey < root->key)
        return my_search (root->left, nkey);
    else
        return my_search (root->right, nkey);
}

ListNode* find_minimum (ListNode* root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}

ListNode* find_maximum (ListNode* root) {
    while (root->right != nullptr)
        root = root->right;
    return root;
}

struct SimpleTree {
    ListNode* root = nullptr;

void my_insert (ListNode *z){
    ListNode* y;
    ListNode* x;
    y = nullptr;
    x = root;
    while (x != nullptr){
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    z->p = y;
    if (y == nullptr)
        root = z;
    else {
        if (z->key < y->key)
            y->left = z;
        else
            y->right = z;
    }
}

void transplant (ListNode *u, ListNode *v) {
    if (u->p == nullptr)
        root = v;
    else {
        if (u == u->p->left)
            u->p->left = v;
        else {
            u->p->right = v;
            if (v != nullptr)
                v->p = u->p;
        }
    }
}

void my_delete (ListNode *z) {
    ListNode* y;
    if (z->left == nullptr)
        transplant (z, z->right);
    else {
        if (z->right == nullptr)
            transplant (z, z->left);
        else {
            y = find_minimum(z->right);
            if (y->p != z) {
                transplant (y, y->right);
                y->right = z->right;
                y->right->p = y;
            }
            transplant (z, y);
            y->left = z->left;
            y->left->p = y;
    }
    }
}
};

void print(ListNode *root) {
    if (root == nullptr)
        return;
    print(root->left);
    cout << root->key << " ";
    print(root->right);
}

void info(ListNode *n, string message, int h) {
    for (int i=0; i<h; i++) {
        cout << "    ";
    }
    cout << message << ": ";
    if (n == nullptr) {
        cout << "-\n";
        return;
    }
    cout << n->key << "\n";
    info(n->left, "left", h+1);
    info(n->right, "right", h+1);
}

int main() {
    char cmd;
    int key;
    SimpleTree tree;
    while (cin >> cmd) {
        if (cmd == '+') {
            cin >> key;
            tree.my_insert(new ListNode(key));
        } else if (cmd == '-') {
            cin >> key;
            tree.my_delete(new ListNode(key));
        } else if (cmd == '?') {
            cin >> key;
            cout << boolalpha << (my_search(tree.root, key) != nullptr) << "\n";
        } else if (cmd == 'p') {
            print(tree.root);
            cout << "\n";
        } else if (cmd == 'i') {
            info(tree.root, "Root", 0);
            cout << "\n";
        } else if (cmd == 'e') {
            return 0;
        }
    }
}
