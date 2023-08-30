#include <bits/stdc++.h>

using namespace std;

int main()
{
    count sort
    int n =6;
    int arr[n] ={56,32,68,21,01,46};
    
    int count[n]={0};
    
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            
            if(arr[i]>arr[j]) count[i]++;
            else count[j]++;
        }
    }
    
    int ans[n];
    for(int i=0;i<n;i++)
        ans[count[i]] = arr[i];
        
    for(auto i : ans)
        cout<<i<<' ';
