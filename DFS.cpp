#include <iostream>
#include<vector>
#include<cstring>
using namespace std;

//Input
// 9 9
// 1 2
// 1 3
// 1 5
// 2 4
// 3 6
// 3 7
// 3 9
// 5 8
// 8 9
vector<int> adj[1001];
bool visited[1001];
void init(){
    int n, m, x, y;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
void dfs(int u){
    cout<<u<<" ";
    visited[u] = true;
    for(int i=0; i<adj[u].size(); i++)
        if(!visited[ adj[u][i] ])
            dfs( adj[u][i] );
}
int main() {
    init();
    dfs(1);
}
