//q1b    DFS of graph recursively

#include<bits/stdc++.h>
using namespace std;

void dfs_rec(int i, vector<int>&visdfs, vector<int>adj[], vector<int>&dfsv){
    if(visdfs[i]==-1){
        visdfs[i]=1;
        dfsv.push_back(i);
        for(auto j:adj[i]){
            dfs_rec(j,visdfs,adj,dfsv);
        }
    }
}

int main(){
    vector<int>adj[]={{3,1}, {0,2,3,6}, {1,4,5}, {1,0}, {2}, {2,6}, {1,5}};
    vector<int>visdfs(7,-1);
    vector<int>dfsv;
    dfs_rec(0,visdfs,adj,dfsv);
    cout<<"The DFS traversal is: ";
    for(int i=0;i<dfsv.size();i++){
        cout<<dfsv[i]<<" ";
    }
}

/*The DFS traversal is: 0 3 1 2 4 5 6*/