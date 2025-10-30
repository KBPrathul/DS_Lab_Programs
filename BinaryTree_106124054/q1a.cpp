//q1    Recursive implementations

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

void preorder(struct bt* root, vector<int>& arr){
    if(root==nullptr){return;}
    arr.push_back(root->val);
    preorder(root->left,arr);
    preorder(root->right,arr);
}

void inorder(struct bt* root, vector<int>& arr){
    if(root==nullptr){return;}
    inorder(root->left,arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}

void postorder(struct bt* root, vector<int>& arr){
    if(root==nullptr){return;}
    postorder(root->left,arr);
    postorder(root->right, arr);
    arr.push_back(root->val);
}

void levelorder(queue<struct bt*>& q, vector<int>& arr) {
    if (q.empty()) return;
    arr.push_back(q.front()->val);
    if (q.front()->left != nullptr) {
        q.push(q.front()->left);
    }
    if (q.front()->right != nullptr) {
        q.push(q.front()->right);
    }
    q.pop();
    levelorder(q, arr);
}

int heightofbt(struct bt* root) {
    if (root == nullptr) {
        return -1;
    }
    return 1 + max(heightofbt(root->left), heightofbt(root->right));
}

void printarr(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of arr: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Enter values: ";
        cin>>arr[i];
    }
    vector<int>preo;
    vector<int>ino;
    vector<int>posto;
    vector<int>levelo;
    struct bt* root = arrtobt(arr);
    queue<struct bt*>tempq;
    tempq.push(root);
    preorder(root, preo);
    inorder(root, ino);
    postorder(root, posto);
    levelorder(tempq,levelo);
    int h=heightofbt(root);
    printarr(preo);
    printarr(ino);
    printarr(posto);
    printarr(levelo);
    cout<<h;
}

/*Enter the size of arr: 5
Enter values: 1
Enter values: 2
Enter values: -1
Enter values: 3
Enter values: 4
1 2 3 4 
3 2 4 1 
3 4 2 1 
1 2 3 4 
2*/