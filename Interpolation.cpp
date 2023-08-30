//interpolation search

#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n;
    cout<<"Enter number of elements\n";
    cin>>n;
    
    cout<<"Enter the elements:\n";
    
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    cout<<"Enter the elements to be searched\n";
    int key;
    cin>>key;
    bool flag = false;
    int l =0,h=n-1;
    while(l<=h){
        int pos = l + ((h-l)/(arr[h]-arr[l]))*(key-arr[l]);
        if(arr[pos]==key){
            cout<<"Key "<<key<<" found at index: "<<pos<<endl;
            flag = true;
            break;
        }
        else if(arr[pos]<key)
            l = pos +1;
        else
            h = pos-1;
    }
    
    if(!flag)   cout<<"Element not found\n";
    
    return 0;
}

