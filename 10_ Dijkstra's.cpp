#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number of vertices\n";
    cin>>n;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<n;i++){
        cout<<"Enter number of edges for node "<<i<<endl;
        int m;
        cin>>m;
        cout<<"Enter destination node and corresponding edge weights\n";
        while(m--){
            pair<int,int> p;
            cin>>p.first>>p.second;
            adj[i].push_back(p);
        }
    }
    
    //dijkstra start
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    int src;
    cout<<"Enter start node\n";
    cin>>src;
    pq.push({0,src});
    vector<int> dist(n,1e9);
    dist[0]=0;
    while(!pq.empty()){
        int curnode = pq.top().second;
        int curdist = pq.top().first;
        pq.pop();
        
        for(auto i : adj[curnode]){
            int nextnode = i.first,nextdist = i.second;
            if(dist[nextnode] > nextdist + dist[curnode]){
                dist[nextnode] = nextdist + dist[curnode];
                pq.push({dist[nextnode],nextnode});
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(dist[i] < 1e9)
            cout<<src<<"->"<<i<<" = "<<dist[i]<<endl;
        else
            cout<<"No edge from "<<src<<" to "<<i<<endl;
    }

    return 0;
}
