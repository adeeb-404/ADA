#include<bits/stdc++.h>
using namespace std;

//SAMPLE INPUT
// 6
// 2
// 1 3
// 2
// 0 2
// 3
// 1 3 4
// 2
// 0 2
// 1
// 2
// 0
// 3


void print(vector<int> adj[],int n){
    for(int i=0;i<n;i++){
        for(auto v : adj[i])
            cout<<v<<" ";
        cout<<endl;
    }
}

void dfs(vector<int> adj[],vector<bool> &vis,int node){
    vis[node]=true;
    
    for(auto i : adj[node]){
        if(!vis[i])
            dfs(adj,vis,i);
    }
}

int main()
{
    int n;
    cout<<"Enter number of vertices\n";
    cin>>n;
    vector<int> adj[n];
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
        cout<<"Enter number of edges for vertex "<<i<<endl;
        int m;
        cin>>m;
        cout<<"Enter "<<m<<" edges\n";
        for(int j=0;j<m;j++){
            int e;
            cin>>e;
            adj[i].push_back(e);
        }
    }
    
    int count=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            count++;
            dfs(adj,vis,i);
        }
    }
    
    if(count==1)
        cout<<"Graph is connected";
    else{
        cout<<"The graph is not connected\nIt has "<<count<<" Components";
    }
 
    return 0;
}

