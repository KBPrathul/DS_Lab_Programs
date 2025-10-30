//q1    Topological sort using DFS

#include <bits/stdc++.h>
using namespace std;

void dfs_rec(int i,vector<int> &visdfs,vector<int> vispath,vector<int>adj[],vector<int> &dfsv,bool &hascycle){
    visdfs[i]=1;
    vispath[i]=1;
    for(auto j:adj[i]){
        if(visdfs[j]==-1){
            dfs_rec(j,visdfs,vispath,adj,dfsv,hascycle);
            if(hascycle) return;
        } 
        else if(vispath[j]==1){ 
            hascycle=true;
            return;
        }
    }
    vispath[i]=0;
    dfsv.push_back(i);
}

int main(){
    vector<int>adj[]={{3,1},{2,6},{4},{1},{},{2},{5}};
    int V=7;
    vector<int>visdfs(V,-1);
    vector<int>vispath(V,0);
    vector<int>dfsv;
    bool hascycle=false;
    for(int i=0;i<V;i++){
        if(visdfs[i]==-1){
            dfs_rec(i,visdfs,vispath,adj,dfsv,hascycle);
        }
    }

    if(hascycle){
        cout<<"Cycle detected!"<<endl;
    }
    else{
        cout<<"The topological sort is: ";
        for (int i=dfsv.size()-1;i>=0;i--){
            cout<<dfsv[i]<<" ";
        }
        cout<<endl;
        cout<<"No cycle detected!"<<endl;
    }
    
    return 0;
}

/*The topological sort is: 0 3 1 6 5 2 4
No cycle detected!*/