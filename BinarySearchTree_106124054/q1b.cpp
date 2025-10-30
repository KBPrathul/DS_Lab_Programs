//q1    Itervative implementation

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

void insert(struct bt* &root, int x){
    if(root==nullptr){
        root=new bt(x);
        return;
    }
    struct bt* temp=root;
    struct bt* prev;
    while(temp!=nullptr){
        prev=temp;
        if(temp->val>x){
            temp=temp->left;
        }
        else if(temp->val<x){
            temp=temp->right;
        }
        else{
            return;
        }
    }
    if(prev->val>x){
        prev->left=new bt(x);
    }
    else{
        prev->right=new bt(x);
    }
    return;
}

void del(struct bt* &root, int x){
    if(root==nullptr){
        cout<<"Tree is empty";
        return;
    }
    
    struct bt* temp = root;
    struct bt* prev = nullptr;
    while(temp != nullptr && temp->val != x){
        prev = temp;
        if(temp->val > x){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    if(temp == nullptr){
        cout<<"No such node exists!";
        return;
    }
    if(temp->left == nullptr && temp->right == nullptr){
        if(prev == nullptr){
            root = nullptr;
        }
        else if(prev->left == temp){
            prev->left = nullptr;
        }
        else{
            prev->right = nullptr;
        }
        delete temp;
    }
    else if(temp->left != nullptr && temp->right != nullptr){
        struct bt* predecessor = temp->left;
        struct bt* predParent = temp;
        while(predecessor->right != nullptr){
            predParent = predecessor;
            predecessor = predecessor->right;
        }
        temp->val = predecessor->val;
        if(predParent == temp){
            predParent->left = predecessor->left;
        }
        else{
            predParent->right = predecessor->left;
        }
        delete predecessor;
    }
    else{
        struct bt* child = (temp->left != nullptr) ? temp->left : temp->right;
        if(prev == nullptr){
            root = child;
        }
        else if(prev->left == temp){
            prev->left = child;
        }
        else{
            prev->right = child;
        }
        delete temp;
    }
}

int min(struct bt* root){
    while(root->left!=nullptr){
        root=root->left;
    }
    return root->val;
}

int max(struct bt* root){
    while(root->right!=nullptr){
        root=root->right;
    }
    return root->val;
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

int main() {
    struct bt* root = nullptr;
    insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    del(root, 50);
    cout<<max(root)<<" "<<min(root)<<endl;
    vector<int>arr;
    levelorder(root,arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}

/*80 20
40 30 70 20 60 80 */