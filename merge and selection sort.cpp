#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minin = i;
        for(int j=i+1;j<n;j++){
            if(arr[minin]>arr[j])
                minin = j;
        }
        swap(arr[minin],arr[i]);
    }
}

void merge(int arr[],int low,int mid,int high){
    int merged[high-low +1];
    
    int i=low,j=mid+1;
    int k =0;
    while(i<=mid&&j<=high){
        if(arr[i]<arr[j])
            merged[k++] = arr[i++];
        else 
            merged[k++] = arr[j++];
    }
    
    while(i<=mid)
        merged[k++]= arr[i++];
        
    while(j<=high)
        merged[k++] = arr[j++];
    
    for(int i=0,j=low;j<=high;i++,j++)
        arr[j]=merged[i];
    
}

void merge_sort(int arr[],int l,int h){
    if(l<h){
        int mid = (l+h)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}

void ms(){
    
    for(int t=0;t<10;t++){
        int n = 100*t;
        int arr[n];
        for(int i=0;i<n;i++)
            arr[i] = rand()%100 +i;
        
        // for(int i =0;i<n;i++)
        //     cout<<arr[i]<<" ";
        clock_t start_t = clock();
        merge_sort(arr,0,n-1);
        clock_t end_t = clock();
        
        // for(int i=0;i<n;i++)
        //     cout<<arr[i]<<" ";
        cout<<endl;
        double mst = (((double)(end_t-start_t))*1000)/CLOCKS_PER_SEC;
        cout<<"time taken by merge sort sort is: "<<mst<<endl;
    }
}

void ss(){
    for(int t=0;t<10;t++){
        int n = 100*t;
        int arr[n];
        for(int i=0;i<n;i++)
            arr[i] = rand()%100 +i;
        
        // for(int i =0;i<n;i++)
        //     cout<<arr[i]<<" ";
        clock_t start_t = clock();
        selection_sort(arr,n);
        clock_t end_t = clock();
        
        merge_sort(arr,0,n-1);
        
        // for(int i=0;i<n;i++)
        //     cout<<arr[i]<<" ";
        cout<<endl;
        double sst = (((double)(end_t-start_t))*1000)/CLOCKS_PER_SEC;
        cout<<"time taken by selection sort is: "<<sst<<endl;
    }
}

int main()
{
    
    ms();
    cout<<"-----------------------------\n";
    ss();

    return 0;
}

