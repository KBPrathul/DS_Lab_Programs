//q1   Checking for valid Red=Black tree

#include<bits/stdc++.h>
using namespace std;


struct node{
    char val;
    node* left;
    node* right;
    node(char c){
        val=c;
        left=nullptr;
        right=nullptr;
    }
};

node* arrtonode(vector<char>arr){
    queue<node*>q;
    node* root=new node(arr[0]);
    q.push(root);
    int i=1;
    while(!q.empty() && i<arr.size()){
        node* temp=q.front();
        q.pop();
        if(i<arr.size() && arr[i]!='x'){
            temp->left=new node(arr[i]);
            q.push(temp->left);
        }
        i++;
        if(i<arr.size() && arr[i]!='x'){
            temp->right=new node(arr[i]);
            q.push(temp->right);
        }
        i++;
    }
    return root;
}

bool redprop(node* root) {
    if (!root) return true;
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        if(temp->val == 'r') {
            if(temp->left && temp->left->val == 'r') return false;
            if(temp->right && temp->right->val == 'r') return false;
        }
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    return true;
}
bool truth=true;
void blackprop(node* root, int curr, int target){
    if(truth==false){return;}
    if(root==nullptr){
        if(curr==target){
            return;
        }
        else{
            truth=false;return;
        }
    }
    if(root->val=='b'){
        curr++;
        blackprop(root->left,curr,target);
        blackprop(root->right,curr,target);
    }
    else{
        blackprop(root->left,curr,target);
        blackprop(root->right,curr,target);
    }
}
bool check(node* root){
    if(root->val=='r'){return false;}
    if(!redprop(root)){return false;}
    node* temp=root;
    int x=0;
    while(temp!=nullptr){
        if(temp->val=='b'){
            x++;
        }
        temp=temp->left;
    }
    blackprop(root,0,x);
    if(!truth){return false;}
    return true;
}

int main(){
    int n;
    cout<<"Enter the value on n: ";
    cin>>n;
    vector<char>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Enter: ";
        cin>>arr[i];
    }
    node* root=arrtonode(arr);
    bool ans=check(root);
    if(ans){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}

/*Enter the value on n: 5
Enter: b
Enter: b
Enter: b
Enter: r
Enter: r
true*/