//q2    Number of rotations in AVL Tree

#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    int height;
    node(int x){
        val=x;
        left=nullptr;
        right=nullptr;
        height=1;
    }
};

int getheight(node* root){
    if(!root){return 0;}
    return root->height;
}

int balfact(node* root){
    if(!root){return 0;}
    return getheight(root->left)-getheight(root->right);
}

int setheight(node* root){
    return 1+max(getheight(root->right),getheight(root->left));
}

node* rightrot(node* root){
    node* temp=root;
    root=temp->left;
    temp->left=root->right;
    root->right=temp;
    temp->height=setheight(temp);
    root->height=setheight(root);
    return root;
}

node* leftrot(node* root){
    node* temp=root;
    root=temp->right;
    temp->right=root->left;
    root->left=temp;
    temp->height=setheight(temp);
    root->height=setheight(root);
    return root;
}

int ans=0;
node* ins(node* root,int x){
    if(!root){
        return new node(x);
    }
    if(x<root->val){
        root->left=ins(root->left,x);
    }
    else if(x>root->val){
        root->right=ins(root->right,x);
    }
    else{
        return root;
    }
    root->height=setheight(root);
    int bal=balfact(root);
    // Left Left
    if(bal>1 && balfact(root->left)>=0){
        ans++;
        return rightrot(root);
    }
    // Left Right
    if(bal>1 && balfact(root->left)<0){
        ans+=2;
        root->left = leftrot(root->left);
        return rightrot(root);
    }
    // Right Right
    if(bal<-1 && balfact(root->right)<=0){
        ans++;
        return leftrot(root);
    }
    // Right Left
    if(bal<-1 && balfact(root->right)>0){
        ans+=2;
        root->right=rightrot(root->right);
        return leftrot(root);
    }
    return root;
}

node* minValueNode(node* root){
    node* current=root;
    while(current && current->left){
        current=current->left;
    }
    return current;
}


node* del(node* root,int x){
    if(!root){
        return root;
    }
    if(x<root->val){
        root->left=del(root->left,x);
    }
    else if(x>root->val){
        root->right = del(root->right, x);
    }
    else{
        if(!root->left || !root->right){
            node* temp=root->left?root->left:root->right;
            if(!temp){
                temp=root;
                root=nullptr;
            }
            else{
                *root=*temp;
            }
            delete temp;
        }
        else{
            node* temp=minValueNode(root->right);
            root->val=temp->val;
            root->right=del(root->right,temp->val);
        }
    }
    if(!root){
        return root;
    }
    root->height=setheight(root);
    int bal=balfact(root);
    if(bal>1 && balfact(root->left)>=0){
        return rightrot(root);
    }
    if(bal>1 && balfact(root->left)<0){
        root->left=leftrot(root->left);
        return rightrot(root);
    }
    if(bal<-1 && balfact(root->right)<=0){
        return leftrot(root);
    }
    if(bal<-1 && balfact(root->right)>0){
        root->right=rightrot(root->right);
        return leftrot(root);
    }
    return root;
}

int main(){
    node* root=nullptr;
    vector<int> keys={10,20,30,40,50,25};
    for(int key:keys){
        root=ins(root,key);
    }
    cout<<endl;
    cout<<ans;
}

/*4*/