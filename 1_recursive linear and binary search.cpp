#include <bits/stdc++.h>
using namespace std;

int linear_search(int arr[],int n,int key){
    if(n<0)
        return -1;
    if(arr[n]==key)
        return n;
    return linear_search(arr,n-1,key);
}

int binary_search(int arr[],int l,int h,int key){
    if(l<=h){
        int mid = (l+h)/2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] > key)
            return binary_search(arr,l,mid-1,key);
        return binary_search(arr,mid+1,h,key);
    }
    return -1;
}

int main()
{
    
    for(int i=1;i<=10;i++){
        int n = 100*i;
        int arr[n];
        for(int i=0;i<n;i++)
            arr[i] = rand()%100 +i;
            
        // for(int i=0;i<n;i++)
        //     cout<<arr[i]<<",";
        
        int key;
        cout<<"\n Enter element to be searched\n";
        key = -1;
        
        clock_t start_t = clock();
        int pos = linear_search(arr,n-1,key);
        clock_t end_t = clock();
        

        double ls = (((double)(end_t - start_t))*1000)/CLOCKS_PER_SEC;
        
        start_t = clock();
        binary_search(arr,0,n-1,key);
        end_t = clock();
        
        double bs = ((double)(end_t- start_t)*1000)/CLOCKS_PER_SEC;
        
        cout<<"Time taken to search in list of "<<n<<" elements for linear search: "<<ls<<" for binary search: "<<bs;
    
}
    return 0;
}


