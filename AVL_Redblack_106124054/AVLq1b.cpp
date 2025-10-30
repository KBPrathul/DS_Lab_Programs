//q1b    Iterative implementation of AVL Tree

#include <bits/stdc++.h>
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

node* ins_iterative(node* root,int x){
    if(!root){
        return new node(x);
    }
    stack<node*>st;
    node* current=root;
    while(current){
        st.push(current);
        if(x<current->val){
            if(!current->left){
                current->left=new node(x);
                break;
            }
            current=current->left;
        }
        else if(x>current->val){
            if(!current->right){
                current->right=new node(x);
                break;
            }
            current=current->right;
        }
        else{
            return root;
        }
    }
    while(!st.empty()){
        node* curr=st.top();
        st.pop();
        curr->height=setheight(curr);
        int bal=balfact(curr);
        node* new_root=nullptr;
        if(bal>1 && balfact(curr->left)>=0){
            new_root=rightrot(curr);
        }
        else if(bal>1 && balfact(curr->left)<0){
            curr->left=leftrot(curr->left);
            new_root=rightrot(curr);
        }
        else if(bal<-1 && balfact(curr->right)<=0){
            new_root=leftrot(curr);
        }
        else if(bal<-1 && balfact(curr->right)>0){
            curr->right=rightrot(curr->right);
            new_root=leftrot(curr);
        }
        if(new_root){
            if(!st.empty()){
                node* parent=st.top();
                if(parent->left==curr){
                    parent->left=new_root;
                }
                else{
                    parent->right=new_root;
                }
            }
            else{
                root=new_root;
            }
        }
    }
    return root;
}

node* del(node* root,int x){
    if(!root){
        return nullptr;
    }
    stack<node*>st;
    node* current=root;
    while(current && current->val!=x){
        st.push(current);
        if(x<current->val){
            current=current->left;
        }
        else{
            current=current->right;
        }
    }
    if(!current){
        return root;
    }
    if(current->left && current->right){
        st.push(current);
        node* successor=current->right;
        while(successor->left){
            st.push(successor);
            successor=successor->left;
        }
        current->val=successor->val;
        current=successor;
    }
    node* child=(current->left)?current->left:current->right;
    if (st.empty()){
        root=child;
    }
    else{
        node* parent=st.top();
        if (parent->left==current) {
            parent->left=child;
        }
        else{
            parent->right=child;
        }
    }
    delete current;
    while(!st.empty()){
        node* curr=st.top();
        st.pop();
        curr->height=setheight(curr);
        int bal=balfact(curr);
        node* new_root=nullptr;
        if (bal>1 && balfact(curr->left)>=0)
            new_root=rightrot(curr);
        else if(bal>1 && balfact(curr->left)<0){
            curr->left=leftrot(curr->left);
            new_root=rightrot(curr);
        }
        else if(bal<-1 && balfact(curr->right)<=0){
            new_root=leftrot(curr);
        }
        else if(bal<-1 && balfact(curr->right)>0){
            curr->right=rightrot(curr->right);
            new_root=leftrot(curr);
        }
        if(new_root){
            if(!st.empty()){
                node* parent=st.top();
                if(parent->left==curr){
                    parent->left=new_root;
                }
                else{
                    parent->right=new_root;
                }
            }
            else{
                root=new_root;
            }
        }
    }
    return root;
}

void inorder(node* root){
    if(root){
        inorder(root->left);
        cout<<root->val<< " ";
        inorder(root->right);
    }
}

int main() {
    node* root=nullptr;
    vector<int>keys={10,20,30,40,50,25};
    for (int key : keys) {
        root = ins_iterative(root, key);
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