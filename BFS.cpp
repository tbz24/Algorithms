#include <iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

// INPUT
// 10 11
// 1 2
// 1 3
// 1 5
// 1 10
// 2 4
// 3 6
// 3 7
// 3 9
// 6 7
// 5 8
// 8 9
bool visited[1001];
vector<int> adj[1001];
void init(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
void bfs(int u){
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        cout<<temp<<" ";
        for(int i=0; i<adj[temp].size(); i++)
            if(!visited[ adj[temp][i] ]){
                q.push(adj[temp][i]);
                visited[adj[temp][i]] = true;
            }
    }
}

int main() {
    init();
    bfs(1);
}
