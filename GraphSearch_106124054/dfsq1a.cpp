//q1a    DFS of Graph iteratively

#include<bits/stdc++.h>
using namespace std;

void dfs_iter(vector<int>&visdfs,vector<vector<int>>adj,vector<int>&dfsv){
    stack<int>st;
    st.push(0);
    dfsv.push_back(0);
    visdfs[0]=1;
    while(!st.empty()){
        int curr=st.top();
        bool truth=false;
        for(int i=0;i<adj[curr].size();i++){
            if(adj[curr][i]==1 && visdfs[i]==-1){
                st.push(i);
                dfsv.push_back(i);
                visdfs[i]=1;
                truth=true;
                break;
            }
        }
        if(!truth){
            st.pop();
        }
    }    
}
int main(){
    vector<vector<int>>adj={{1,1,0,1,0,0,0},{1,1,1,1,0,0,1},{0,1,1,0,1,1,0},{1,1,0,1,0,0,0},{0,0,1,0,1,0,0},{0,0,1,0,0,1,1},{0,1,0,0,0,1,1}};
    vector<int>visdfs(7,-1);
    vector<int>dfsv;
    dfs_iter(visdfs,adj,dfsv);
    cout<<"The DFS traversal is: ";
    for(int i=0;i<dfsv.size();i++){
        cout<<dfsv[i]<<" ";
    }
}

/*The DFS traversal is: 0 1 2 4 5 6 3*/