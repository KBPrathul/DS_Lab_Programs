//q1a    Recursive implementaton of AVL Tree

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
        return rightrot(root);
    }
    // Left Right
    if(bal>1 && balfact(root->left)<0){
        root->left = leftrot(root->left);
        return rightrot(root);
    }
    // Right Right
    if(bal<-1 && balfact(root->right)<=0){
        return leftrot(root);
    }
    // Right Left
    if(bal<-1 && balfact(root->right)>0){
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

void inorder(node* root) {
    if (root) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

int main() {
    node* root=nullptr;
    vector<int>keys={10,20,30,40,50,25};
    for (int key : keys) {
        root = ins(root, key);
    }
    cout << "\nInorder traversal at start: ";
    inorder(root);
    cout << endl;
    root = del(root, 10);
    cout << "Inorder traversal after deleting 10: ";
    inorder(root);
    cout << endl;
    root = del(root, 40);
    cout << "Inorder traversal after deleting 40: ";
    inorder(root);
    cout << endl;

    return 0;
}

/*
Inorder traversal at start: 10 20 25 30 40 50 
Inorder traversal after deleting 10: 20 25 30 40 50 
Inorder traversal after deleting 40: 20 25 30 50 */