//q2    Lowest common ancestor in BT

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

bool levelorder(struct bt* root, int x, int y){
    bool xt=false,yt=false;
    queue<struct bt*>q;
    q.push(root);
    while(!q.empty()){
        if(q.front()->val==x){xt=true;}
        if(q.front()->val==y){yt=true;}
        if(q.front()->left!=nullptr){
            q.push(q.front()->left);
        }
        if(q.front()->right!=nullptr){
            q.push(q.front()->right);
        }
        q.pop();
    }
    if(xt==true && yt==true){return true;}
    return false;
}

void LCA(struct bt* root, int x, int y, int& ans){
    if(levelorder(root,x,y)==true){
        ans=root->val;
        LCA(root->left,x,y,ans);
        LCA(root->right,x,y,ans);
    }
    else{
        return;
    }
}


int main(){
    int x,y,n;
    cout<<"Enter the value of n: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Enter value: ";
        cin>>arr[i];
    }
    cout<<"Enter the value of x & y: ";
    cin>>x>>y;
    struct bt* root=arrtobt(arr);
    int ans=-1;
    LCA(root,x,y,ans);
    cout<<ans;
}

/*Enter the value of n: 7
Enter value: 5
Enter value: 3
Enter value: 2
Enter value: 4
Enter value: 5
Enter value: -1
Enter value: 1
Enter the value of x & y: 4 5
3*/