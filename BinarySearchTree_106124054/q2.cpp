//q2    Checking whether a BT is a BST

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

struct bt* arrtobt(vector<int>arr){
    queue<struct bt*>q;
    struct bt* root=new bt(arr[0]);
    q.push(root);
    int i=1;
    while(!q.empty() && i<arr.size()){
        struct bt* temp=q.front();
        q.pop();
        if(arr[i]!=-1 && i<arr.size()){
            temp->left=new bt(arr[i]);
            q.push(temp->left);
        }
        i++;
        if(arr[i]!=-1 && i<arr.size()){
            temp->right=new bt(arr[i]);
            q.push(temp->right);
        }
        i++;
    }
    return root;
}

void inorder(struct bt* root, vector<int>& arr){
    if(root==nullptr){return;}
    inorder(root->left,arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Enter the value: ";
        cin>>arr[i];
    }
    struct bt* root=arrtobt(arr);
    vector<int>inord;
    inorder(root,inord);
    bool truth=true;
    for(int i=0;i<inord.size()-1;i++){
        if(inord[i]>inord[i+1]){
            cout<<"Not a BST!";
            truth=false;
            break;
        }
    }
    if(truth){
        cout<<"It is a BST!";
    }
}

/*Enter the size of the array: 12
Enter the value: 25
Enter the value: 18
Enter the value: 30
Enter the value: 12
Enter the value: 20
Enter the value: 28
Enter the value: 40
Enter the value: -1
Enter the value: -1
Enter the value: -1
Enter the value: -1
Enter the value: 27
It is a BST!*/