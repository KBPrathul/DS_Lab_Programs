//q2    Implementation of red-black tree
//Got help from internet to implement this

#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node *parent;
    node *left;
    node *right;
    int red;

    node(int x) : val(x), parent(nullptr), left(nullptr), right(nullptr), red(1) {}
};
node* NIL;

void init() {
    NIL = new node(0);
    NIL->red = 0;
    NIL->left = nullptr;
    NIL->right = nullptr;
    NIL->parent = nullptr;
}

void leftRotate(node*& root, node* x) {
    node* y = x->right;
    x->right = y->left;
    if (y->left != NIL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void rightRotate(node*& root, node* x) {
    node* y = x->left;
    x->left = y->right;
    if (y->right != NIL) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

void insertFixup(node*& root, node* k) {
    node* u;
    while (k->parent->red == 1) {
        if (k->parent == k->parent->parent->right) {
            u = k->parent->parent->left;
            if (u->red == 1) {
                u->red = 0;
                k->parent->red = 0;
                k->parent->parent->red = 1;
                k = k->parent->parent;
            } else {
                if (k == k->parent->left) {
                    k = k->parent;
                    rightRotate(root, k);
                }
                k->parent->red = 0;
                k->parent->parent->red = 1;
                leftRotate(root, k->parent->parent);
            }
        } else {
            u = k->parent->parent->right;
            if (u->red == 1) {
                u->red = 0;
                k->parent->red = 0;
                k->parent->parent->red = 1;
                k = k->parent->parent;
            } else {
                if (k == k->parent->right) {
                    k = k->parent;
                    leftRotate(root, k);
                }
                k->parent->red = 0;
                k->parent->parent->red = 1;
                rightRotate(root, k->parent->parent);
            }
        }
        if (k == root) {
            break;
        }
    }
    root->red = 0;
}

void insert(node*& root, int key) {
    node* new_node = new node(key);
    new_node->left = NIL;
    new_node->right = NIL;
    node* y = nullptr;
    node* x = root;
    while (x != NIL) {
        y = x;
        if (new_node->val < x->val) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    new_node->parent = y;
    if (y == nullptr) {
        root = new_node;
    } else if (new_node->val < y->val) {
        y->left = new_node;
    } else {
        y->right = new_node;
    }
    if (new_node->parent == nullptr) {
        new_node->red = 0;
        return;
    }
    if (new_node->parent->parent == nullptr) {
        return;
    }
    insertFixup(root, new_node);
}

void transplant(node*& root, node* u, node* v) {
    if (u->parent == nullptr) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

node* minimum(node* n) {
    while (n->left != NIL) {
        n = n->left;
    }
    return n;
}

void deleteFixup(node*& root, node* x) {
    node* s;
    while (x != root && x->red == 0) {
        if (x == x->parent->left) {
            s = x->parent->right;
            if (s->red == 1) {
                s->red = 0;
                x->parent->red = 1;
                leftRotate(root, x->parent);
                s = x->parent->right;
            }
            if (s->left->red == 0 && s->right->red == 0) {
                s->red = 1;
                x = x->parent;
            } else {
                if (s->right->red == 0) {
                    s->left->red = 0;
                    s->red = 1;
                    rightRotate(root, s);
                    s = x->parent->right;
                }
                // Case 4
                s->red = x->parent->red;
                x->parent->red = 0;
                s->right->red = 0;
                leftRotate(root, x->parent);
                x = root;
            }
        } else {
            s = x->parent->left;
            if (s->red == 1) {
                s->red = 0;
                x->parent->red = 1;
                rightRotate(root, x->parent);
                s = x->parent->left;
            }
            if (s->right->red == 0 && s->left->red == 0) {
                s->red = 1;
                x = x->parent;
            } else {
                if (s->left->red == 0) {
                    s->right->red = 0;
                    s->red = 1;
                    leftRotate(root, s);
                    s = x->parent->left;
                }
                // Case 4
                s->red = x->parent->red;
                x->parent->red = 0;
                s->left->red = 0;
                rightRotate(root, x->parent);
                x = root;
            }
        }
    }
    x->red = 0;
}

void deleteNode(node*& root, int key) {
    node* z = root;
    node* x, *y;
    while (z != NIL && z->val != key) {
        if (z->val < key) z = z->right;
        else z = z->left;
    }
    if (z == NIL) {
        cout << "Key not found in the tree" << endl;
        return;
    }
    y = z;
    int y_original_color = y->red;
    if (z->left == NIL) {
        x = z->right;
        transplant(root, z, z->right);
    } else if (z->right == NIL) {
        x = z->left;
        transplant(root, z, z->left);
    } else {
        y = minimum(z->right);
        y_original_color = y->red;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        } else {
            transplant(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(root, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->red = z->red;
    }
    delete z;
    if (y_original_color == 0) {
        deleteFixup(root, x);
    }
}

void printTree(node* root) {
    if (root == NIL) {
        cout << "Tree is empty." << endl;
        return;
    }
    queue<node*> q;
    q.push(root);
    cout << "Tree (Value[Color], R=1, B=0):" << endl;
    while (!q.empty()) {
        int level_size = q.size();
        for (int i = 0; i < level_size; ++i) {
            node* temp = q.front();
            q.pop();

            if (temp != NIL) {
                cout << " " << temp->val << "[" << (temp->red ? "R" : "B") << "] ";
                q.push(temp->left);
                q.push(temp->right);
            } else {
                cout << " NIL[B] ";
            }
        }
        cout << endl;
    }
}

int main() {
    init();
    node* root = NIL;
    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);
    insert(root, 25);
    cout << "Tree after insertions:" << endl;
    printTree(root);
    cout << "\n----------------------------------\n";
    cout << "Deleting 10:" << endl;
    deleteNode(root, 10);
    printTree(root);
    cout << "\n----------------------------------\n";
}

/*Tree after insertions:
Tree (Value[Color], R=1, B=0):
 20[B] 
 10[B]  40[R] 
 NIL[B]  NIL[B]  30[B]  50[B] 
 25[R]  NIL[B]  NIL[B]  NIL[B] 
 NIL[B]  NIL[B] 

----------------------------------
Deleting 10:
Tree (Value[Color], R=1, B=0):
 40[B]
 25[R]  50[B]
 20[B]  30[B]  NIL[B]  NIL[B]
 NIL[B]  NIL[B]  NIL[B]  NIL[B]

----------------------------------*/