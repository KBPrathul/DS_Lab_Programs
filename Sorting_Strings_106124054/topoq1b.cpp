//q2    Topological sort using Kanh's algorithm

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>adj[]={{3,1}, {2,6}, {4}, {1}, {}, {2}, {5}};
    int n=7;
    vector<int>vis(n,-1);
    vector<int>deg(n,0);
    vector<int>ans;
    for(int i=0;i<n;i++){
        for(auto j:adj[i]){
            deg[j]++;
        }
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(deg[i]==0){
            q.push(i);
            vis[i]=1;
            ans.push_back(i);
        }
    }
    if(q.empty()){
        cout<<"Cycle detected!"<<endl;
    }
    else{
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto i:adj[curr]){
                deg[i]--;
                if(deg[i]==0 && vis[i]==-1){
                    q.push(i);
                    vis[i]=1;
                    ans.push_back(i);
                }
            }
        }
        cout<<"The topological sort is: ";
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }
}

/*The topological sort is: 0 3 1 6 5 2 4*/