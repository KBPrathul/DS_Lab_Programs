//q3    Finding largest BST in a BT

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

int nodes(struct bt* root){
    if(root==nullptr){return 0;}
    return 1+nodes(root->left)+nodes(root->right);
}

bool checker(struct bt* root, int mx, int mn){
    if(root==nullptr){return true;}
    if(root->val<=mn || root->val>=mx){return false;}
    return checker(root->left,root->val,mn) && checker(root->right,mx,root->val);
}

void isbst(struct bt* root, int &ans){
    if(checker(root,INT_MAX,INT_MIN)){
        ans=max(ans,nodes(root));
    }
    else{
        isbst(root->left,ans);
        isbst(root->right,ans);
        return;
    }
}

int main(){
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Enter the value: ";
        cin>>arr[i];
    }
    struct bt* root=arrtobt(arr);
    int ans=0;
    isbst(root,ans);
    cout<<ans;
}

/*Enter the number of nodes: 7
Enter the value: 10
Enter the value: 6
Enter the value: 11
Enter the value: 3
Enter the value: 7
Enter the value: 12
Enter the value: 13
3*/