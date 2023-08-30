#include <bits/stdc++.h>
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


int main()
{
    int n;
    cout<<"Enter number of nodes\n";
    cin>>n;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<n;i++){
        cout<<"Enter number of vertices node "<<i<<" is connected to\n";
        int m;
        cin>>m;
        cout<<"Enter destination node and corresponding edge weight\n";
        while(m--){
            pair<int,int> p;
            cin>>p.first>>p.second;
            adj[i].push_back(p);
        }
    }
    
    vector<vector<int>> distance(n,vector<int>(n,1e9));
    for(int i=0;i<n;i++){
        for(auto n : adj[i]){
            distance[n.first][i] = distance[i][n.first] = n.second;
        }
    }

    for(int i=0;i<n;i++)
        distance[i][i]=0;
    
    for(int via=0;via<n;via++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                distance[i][j]=min(distance[i][j],distance[i][via]+distance[via][j]);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(distance[i][j]<1e9)
                cout<<i<<"->"<<j<<"="<<distance[i][j]<<endl;
            else
                cout<<"No edge from "<<i<<" to "<<j<<endl;
        }
    }

    return 0;
}

