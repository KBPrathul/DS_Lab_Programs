//q1    Recursive implementation

#include<bits/stdc++.h>
using namespace std;

struct bt{
    int val;
    struct bt* left;
    struct bt* right;
    bt(int x){
        val=x;
        left=nullptr;
        right=nullptr;
    }
};

struct bt* arrtobt(vector<int>&arr){
    queue<struct bt*>q;
    struct bt* root=new bt(arr[0]);
    q.push(root);
    int ptr=1;
    while(!q.empty() && ptr<arr.size()){
        struct bt* temp=q.front();
        q.pop();
        if(ptr<arr.size() && arr[ptr]!=-1){
            temp->left=new bt(arr[ptr]);
            q.push(temp->left);
        }
        ptr++;
        if(ptr<arr.size() && arr[ptr]!=-1){
            temp->right=new bt(arr[ptr]);
            q.push(temp->right);
        }
        ptr++;
    }
    return root;
}

struct bt* insert(struct bt* root, int x){
    if(root==nullptr){
        root=new bt(x);
        return root;
    }
    if(root->val>x){
        root->left=insert(root->left,x);
    }
    else if(root->val<x){
        root->right=insert(root->right,x);
    }
    return root;
}

struct bt* deleteNode(struct bt* root, int x) {
    if (root == nullptr) {
        return root;
    }
    if (x < root->val) {
        root->left = deleteNode(root->left, x);
    } 
    else if (x > root->val) {
        root->right = deleteNode(root->right, x);
    } 
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        else if (root->left == nullptr) {
            struct bt* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            struct bt* temp = root->left;
            delete root;
            return temp;
        }
        else {
            struct bt* successor = root->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }
    }
    return root;
}

void del(struct bt* &root, int x) {
    root = deleteNode(root, x);
}

void levelorder(struct bt* root, vector<int>&arr){
    queue<struct bt*>q;
    q.push(root);
    while(!q.empty()){
        arr.push_back(q.front()->val);
        if(q.front()->left!=nullptr){
            q.push(q.front()->left);
        }
        if(q.front()->right!=nullptr){
            q.push(q.front()->right);
        }
        q.pop();
    }
}

int min(struct bt* root){
    if(root->left==nullptr){return root->val;}
    root=root->left;
    min(root);
}

int max(struct bt* root){
    if(root->right==nullptr){return root->val;}
    root=root->right;
    max(root);
}

int main() {
    struct bt* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    del(root, 50);
    cout << max(root) << " " << min(root) << endl;
    vector<int> arr;
    levelorder(root, arr);
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}

/*80 20
60 30 70 20 40 80*/