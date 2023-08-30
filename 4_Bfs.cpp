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

int main()
{
    int n;
    cout<<"Enter number of vertices\n";
    cin>>n;
    vector<int> adj[n];
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
    
    queue<int> q;
    vector<bool> vis(n,false);
    cout<<"Enter start node\n";
    int st;
    cin>>st;
    cout<<"------------------------------------------------\n\n";
    q.push(st);
    vis[st]=true;
    cout<<"Reachable nodes are:\n";
    while(!q.empty()){
        int cur_node = q.front();
        q.pop();
        cout<<cur_node<<" ";
        for(auto i : adj[cur_node]){
            if(!vis[i]){
                vis[i]=true;
                q.push(i);
            }
        }
    }

    return 0;
}

