//q1    Iterative implementations

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
        if(i<arr.size() && arr[i]!=-1){
            q.front()->left=new bt(arr[i]);
            q.push(q.front()->left);
        }
        i++;
        if(i<arr.size() && arr[i]!=-1){
            q.front()->right=new bt(arr[i]);
            q.push(q.front()->right);
        }
        i++;
        q.pop();
    }
    return root;
}

void preorder(struct bt* root, vector<int>&arr){
    stack<struct bt*>st;
    st.push(root);
    while(!st.empty()){
        struct bt* temp=st.top();
        arr.push_back(temp->val);
        st.pop();
        if(temp->right!=nullptr) st.push(temp->right);
        if(temp->left!=nullptr) st.push(temp->left);
    }
}

void inorder(struct bt* root, vector<int>& arr) {
    stack<struct bt*>st;
    struct bt* current=root;
    while(current!=nullptr||!st.empty()){
        while(current!=nullptr){
            st.push(current);
            current=current->left;
        }
        current=st.top();
        st.pop();
        arr.push_back(current->val);
        current=current->right;
    }
}

void postorder(struct bt* root, vector<int>& arr){
    if(root == nullptr) return;
    stack<struct bt*> st1, st2;
    st1.push(root);
    while(!st1.empty()){
        struct bt* temp = st1.top();
        st1.pop();
        st2.push(temp);
        
        if(temp->left != nullptr) st1.push(temp->left);
        if(temp->right != nullptr) st1.push(temp->right);
    }
    while(!st2.empty()){
        arr.push_back(st2.top()->val);
        st2.pop();
    }
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

int heightofbt(struct bt* root) {
    if (root == nullptr) {
        return 0;
    }
    queue<struct bt*> q;
    q.push(root);
    int height = 0;
    
    while (!q.empty()) {
        int levelSize = q.size();
        height++;
        for (int i = 0; i < levelSize; i++) {
            struct bt* currentNode = q.front();
            q.pop();
            if (currentNode->left != nullptr) {
                q.push(currentNode->left);
            }
            if (currentNode->right != nullptr) {
                q.push(currentNode->right);
            }
        }
    }
    return height;
}

void printarr(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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
    vector<int>preord;
    preorder(root,preord);
    vector<int>inord;
    inorder(root,inord);
    vector<int>postord;
    postorder(root,postord);
    vector<int>levelord;
    levelorder(root,levelord);
    int h=heightofbt(root);
    printarr(preord);
    printarr(inord);
    printarr(postord);
    printarr(levelord);
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