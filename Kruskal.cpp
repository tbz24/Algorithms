#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//input
// 6 9
// 1 2 12
// 1 3 4
// 2 3 1
// 2 4 5
// 2 5 3
// 3 5 2
// 4 5 3
// 4 6 10
// 5 6 8
struct edge{
    int src, dst;
    int w;
};
int n, m;
int parent[1001], size[1001];
vector<edge> canh;

void make_set(){
    for(int i=1; i<=n; i++){
        parent[i] = i;
        size[i] = 1;
    }
}
int find(int v){
    if(v==parent[v])    return v;
    return parent[v] = find(parent[v]);
}
bool Union(int a, int b){
    a = find(a);
    b=find(b);
    if(a==b)    return false;
    if(size[a] < size[b])   swap(a,b);
    parent[b] = a;
    size[a] += size[b];
    return true;
}
void input(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x, y, w;   cin>>x>>y>>w;
        edge e;
        e.src = x, e.dst = y, e.w = w;
        canh.push_back(e);
    }
}
bool cmp(edge a, edge b){
    return a.w < b.w;
}
void kruskal(){
    //tao cay khung cuc tieu rong
    vector<edge> mst;
    int d=0;    //do lon mst
    //sort tang dan
    sort(canh.begin(), canh.end(), cmp);
    
    for(int i=0; i<m; i++){
        if(mst.size() == n-1)   break;
        edge e = canh[i];       // canh e la nho nhat tai thoi diem dang xor_eqconst_cast
        if(Union(e.src, e.dst)){
            mst.push_back(e);
            d += e.w;
        }
    }
    
    if(mst.size() != n-1)
        cout<<"Do thi k lien thong, k ton tai mst";
    else{
        cout<<"MST :"<<d<<endl;
        for(auto it:mst)
            cout<<it.src<<" "<<it.dst<<" "<<it.w<<endl;
    }
}
int main(){
    input();
    make_set();
    kruskal();
}
