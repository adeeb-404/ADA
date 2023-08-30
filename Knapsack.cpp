#include <bits/stdc++.h>

using namespace std;

//SAMPLE INPUT
// 3
// 10 60
// 20 100
// 30 120
// 50


int main()
{
    int n,wt;
    cout<<"Enter number of Items\n";
    cin>>n;
    cout<<"Enter weight and value of each item in order\n";
    int value[n],weight[n];
    for(int i=0;i<n;i++)
        cin>>weight[i]>>value[i];
    
    cout<<"Enter the weight bag can carry\n";
    cin>>wt;
    
    vector<vector<int>> dp(n+1,vector<int>(wt+1,0));
    for(int i=1;i<=n;i++){
        for(int w=1;w<=wt;w++){
            int take =0;
            if(weight[i-1] <= w)
                take = value[i-1] + dp[i-1][w-weight[i-1]];
            int nottake = dp[i-1][w];
            dp[i][w] = max(take,nottake);
        }
    }
    
    cout<<"Maximum profit : "<<dp[n][wt];

    return 0;
}
