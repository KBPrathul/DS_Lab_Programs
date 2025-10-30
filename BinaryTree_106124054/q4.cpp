//q4    Maximum path sum in BT

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

int pathsum(struct bt* root, int &ans){
    if(root==nullptr){
        return 0;
    }
    int leftsum=max(0,pathsum(root->left,ans));
    int rightsum=max(0,pathsum(root->right,ans));
    ans=max(ans,root->val+leftsum+rightsum);
    return root->val+max(leftsum,rightsum);
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Enter value: ";
        cin>>arr[i];
    }
    int ans=INT_MIN;
    struct bt* root=arrtobt(arr);
    pathsum(root,ans);
    cout<<ans;
}

/*Enter the size of array: 7
Enter value: -10
Enter value: 9
Enter value: 20
Enter value: -1
Enter value: -1
Enter value: 15
Enter value: 7
42*/