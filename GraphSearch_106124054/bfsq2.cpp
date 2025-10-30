//q2    Shortest path between 2 points of graph

#include<bits/stdc++.h>
using namespace std;

int shortestPath(const vector<vector<int>>& grid, pair<int, int> start, pair<int, int> end) {
    if (grid[start.first][start.second]==0 || grid[end.first][end.second]==0){
        return -1;
    }
    int rows=grid.size();
    int cols=grid[0].size();
    vector<vector<int>>dist(rows,vector<int>(cols,-1));
    queue<pair<int,int>>q;
    q.push(start);
    dist[start.first][start.second]=0;
    int dr[]={-1,1,0,0};
    int dc[]={0,0,-1,1};
    while(!q.empty()){
        pair<int,int>curr=q.front();
        q.pop();
        int r=curr.first;
        int c=curr.second;
        if(r==end.first && c==end.second){
            return dist[r][c];
        }
        for(int i=0;i<4;i++){
            int newr=r+dr[i];
            int newc=c+dc[i];
            if (newr >=0 && newr<rows && newc>=0 && newc<cols && grid[newr][newc]==1 && dist[newr][newc]==-1){
                dist[newr][newc]=dist[r][c]+1;
                q.push({newr,newc});
            }
        }
    }
    return -1;
}

int main(){
    int a,b;
    cin>>a>>b;
    vector<vector<int>>adj(a,vector<int>(b));
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>adj[i][j];
        }
    }
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    cout<<shortestPath(adj,{x1, y1},{x2, y2})<<endl;
}

/*4 4
1 1 0 1
0 1 1 0
1 0 1 1
1 1 1 1
0 0 3 3
6*/