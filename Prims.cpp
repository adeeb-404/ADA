#include<bits/stdc++.h>
using namespace std;

//SAMPLE INPUT
// 5
// 2
// 1 1
// 3 2
// 2
// 0 1
// 2 6
// 3
// 1 6
// 3 3
// 4 4
// 2
// 0 2
// 2 3
// 1
// 2 4


void print(vector<pair<int,int>> adj[],int n){
    for(int i=0;i<n;i++){
        for(auto v : adj[i])
            cout<<v.first<<" "<<v.second<<endl;
        cout<<endl;
    }
}


int main()
{
    int n;
    cout<<"Enter number of vertices\n";
    cin>>n;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<n;i++){
        cout<<"Enter number of vertices node "<<i<<" is connected to\n";
        int m;
        cin>>m;
        cout<<"Enter destination node and corresponding edge weight\n";
        while(m--){
            pair<int,int> p;
            cin>>p.first;
            cin>>p.second;
            adj[i].push_back(p);
        }
    }
    
    //prims start
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<bool> vis(n,false);
    pq.push({0,0});
    int dist =0;
    
    while(!pq.empty()){
        int curnode = pq.top().second;
        int curdist = pq.top().first;
        pq.pop();
        
        if(vis[curnode])    continue;
        vis[curnode] = true;
        dist +=curdist;
        for(auto i : adj[curnode]){
            if(!vis[i.first])
                pq.push({i.second,i.first});
        }
    }

    cout<<"The Minimum Spanning Distance is "<<dist;

    return 0;
}
