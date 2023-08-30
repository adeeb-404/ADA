#include<bits/stdc++.h>
using namespace std;

//SAMPLE INPUT
// 5 
// 2
// 1 3
// 1
// 2
// 1
// 4
// 1
// 2
// 0



void print(vector<int> adj[],int n){
    for(int i=0;i<n;i++){
        for(auto v : adj[i])
            cout<<v<<" ";
        cout<<endl;
    }
}

void dfs(vector<int> adj[],vector<bool> &vis,int node,stack<int>&st){
    vis[node]=true;
    
    for(auto i : adj[node]){
        if(!vis[i])
            dfs(adj,vis,i,st);
    }
    st.push(node);
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
    stack<int> st;

    dfs(adj,vis,0,st);


    
    cout<<"-------------\n\n";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
 
    return 0;
}
