#include<bits/stdc++.h>
using namespace std;

//INPUT
// 6
// 3 34 4 12 5 2
// 9

void subset_sum(vector<int> &v,int in,int &n,vector<int> ds,int sum){
    if(in==n){
        if(sum==0){
            for(auto i : ds)
                cout<<i<<" ";
            cout<<endl;
        }
        return;
    }
    
    if(v[in] <= sum){
        ds.push_back(v[in]);
        subset_sum(v,in+1,n,ds,sum-v[in]);
        ds.pop_back();
    }
    
    subset_sum(v,in+1,n,ds,sum);
}

int main()
{
    cout<<"Enter number of elements\n";
    int n;
    cin>>n;
    vector<int> v(n,0);
    cout<<"Enter elements\n";
    for(int i=0;i<n;i++)
        cin>>v[i];
        
    cout<<"Enter the sum\n";
    int sum;
    cin>>sum;
    
    vector<int> ds;
    
    subset_sum(v,0,n,ds,sum);

    return 0;
}
