//q1b    BFS of Graph recursively

#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int>&vis, vector<int>adj[],vector<int>&bfsv,queue<int>&q){
    if(q.empty()){return;}
    int curr=q.front();
    q.pop();
    for(auto i:adj[curr]){
        if(vis[i]==-1){
            q.push(i);
            bfsv.push_back(i);
            vis[i]=1;
        }
    }
    bfs(vis,adj,bfsv,q);
}

int main(){
    vector<int>adj[]={{3,1}, {0,2,3,6}, {1,4,5}, {1,0}, {2}, {2,6}, {1,5}};
    vector<int>visbfs(7,-1);
    vector<int>bfsv;
    queue<int>q;
    q.push(0);
    bfsv.push_back(0);
    visbfs[0]=1;
    bfs(visbfs,adj,bfsv,q);
    cout<<"The BFS traversal is: ";
    for(int i=0;i<bfsv.size();i++){
        cout<<bfsv[i]<<" ";
    }
}

/*The BFS traversal is: 0 3 1 2 6 4 5*/