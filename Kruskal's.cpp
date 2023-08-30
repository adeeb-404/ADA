#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,parent;
    public:
        DisjointSet(int n){
            rank.resize(n,0);
            parent.resize(n,0);
            for(int i=0;i<n;i++)
                parent[i] =i;
        }
        
        int findPar(int node){
            if(parent[node]==node)  return node;
            return parent[node] = findPar(parent[node]);
        }
        
        void unionByRank(int u,int v){
            int p_u = findPar(u);
            int p_v = findPar(v);
            
            if(p_u==p_v)    return;
            if(rank[p_u] < rank[p_v])   parent[p_u] = p_v;
            else if(rank[p_v] < rank[p_u]){
                parent[p_v] = p_u;
            }
            else{
                parent[p_v] = p_u;
                rank[p_u]++;
            }
        }
};


struct edge{
    int u;
    int v;
    int wt;
};

bool cmp(edge &a,edge &b){
    return a.wt<b.wt;
}

int main(){
    
    cout<<"Enter number of vertices and edges\n";
    int V,E;
    cin>>V>>E;
    
    vector<edge> edges;
    cout<<"Enter the edges along with weights\n";
    
    while(E--){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({u,v,wt});
    }
    
    sort(edges.begin(),edges.end(),cmp);
    
    DisjointSet ds(V);
    int cost =0;
    
    for(edge e : edges){
        int u = e.u;
        int v = e.v;
        int wt = e.wt;
        
        if(ds.findPar(u) != ds.findPar(v)){
            cost +=wt;
            ds.unionByRank(u,v);
        }
    }
    
    cout<<cost;
    
    return 0;
}

