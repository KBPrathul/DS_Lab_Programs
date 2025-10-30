//q3    Alert system in a town

#include<bits/stdc++.h>
using namespace std;

struct bt{
    int val;
    struct bt* left;
    struct bt* right;
    bt(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

struct bt* arrtobt(vector<int> arr){
    if(arr.empty() || arr[0] == -1) return nullptr;
    queue<struct bt*> q;
    struct bt* root = new bt(arr[0]);
    q.push(root);
    int i = 1;
    while(!q.empty() && i < arr.size()){
        struct bt* temp = q.front();
        q.pop();
        if(i < arr.size() && arr[i] != -1){
            temp->left = new bt(arr[i]);
            q.push(temp->left);
        }
        i++;
        if(i < arr.size() && arr[i] != -1){
            temp->right = new bt(arr[i]);
            q.push(temp->right);
        }
        i++;
    }
    return root;
}

struct bt* findTarget(struct bt* root, int target){
    if(root == nullptr) return nullptr;
    if(root->val == target) return root;
    struct bt* left = findTarget(root->left, target);
    if(left != nullptr) return left;
    return findTarget(root->right, target);
}

void ParentMap(struct bt* root, unordered_map<struct bt*, struct bt*>& parentMap){
    if(root == nullptr) return;
    if(root->left != nullptr){
        parentMap[root->left] = root;
        ParentMap(root->left, parentMap);
    }
    if(root->right != nullptr){
        parentMap[root->right] = root;
        ParentMap(root->right, parentMap);
    }
}

vector<int> findK(struct bt* root, int target, int k){
    vector<int> result;
    struct bt* targetNode = findTarget(root, target);
    if(targetNode == nullptr) return result;
    unordered_map<struct bt*, struct bt*> parentMap;
    ParentMap(root, parentMap);
    queue<struct bt*> q;
    unordered_set<struct bt*> visited;
    q.push(targetNode);
    visited.insert(targetNode);
    int currentDistance = 0;
    while(!q.empty() && currentDistance < k){
        int levelSize = q.size();
        for(int i = 0; i < levelSize; i++){
            struct bt* current = q.front();
            q.pop();
            if(current->left != nullptr && visited.find(current->left) == visited.end()){
                q.push(current->left);
                visited.insert(current->left);
            }
            if(current->right != nullptr && visited.find(current->right) == visited.end()){
                q.push(current->right);
                visited.insert(current->right);
            }
            if(parentMap.find(current) != parentMap.end() && 
               visited.find(parentMap[current]) == visited.end()){
                q.push(parentMap[current]);
                visited.insert(parentMap[current]);
            }
        }
        currentDistance++;
    }
    while(!q.empty()){
        result.push_back(q.front()->val);
        q.pop();
    }
    return result;
}

int main(){
    vector<int> arr = {10, 6, 14, 4, 8, 12, 16, -1, -1, 7, 9};
    int target = 6;
    int k = 2;
    struct bt* root = arrtobt(arr);
    vector<int> alerted = findK(root, target, k);
    for(int i = 0; i < alerted.size(); i++){
        cout << alerted[i];
    }
    return 0;
}

/*7 9 14*/