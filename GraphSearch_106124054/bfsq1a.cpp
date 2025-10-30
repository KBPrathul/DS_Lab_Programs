//q1a    BFS of Graph iteratively

#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int>&vis, vector<vector<int>>adj,vector<int>&bfsv){
    queue<int>q;
    q.push(0);
    vis[0]=1;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        bfsv.push_back(curr);
        for(int i=0;i<adj[curr].size();i++){
            if(adj[curr][i]==1 && vis[i]==-1){
                q.push(i);
                vis[i]=1;
            }
        }
    }
}

int main(){
    vector<vector<int>>adj={{1,1,0,1,0,0,0},{1,1,1,1,0,0,1},{0,1,1,0,1,1,0},{1,1,0,1,0,0,0},{0,0,1,0,1,0,0},{0,0,1,0,0,1,1},{0,1,0,0,0,1,1}};
    vector<int>visbfs(7,-1);
    vector<int>bfsv;
    bfs(visbfs,adj,bfsv);
    cout<<"The BFS traversal is: ";
    for(int i=0;i<bfsv.size();i++){
        cout<<bfsv[i]<<" ";
    }
}

/*The BFS traversal is: 0 1 3 2 6 4 5*/