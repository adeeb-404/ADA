#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int mini =i;
        for(int j=i+1;j<n;j++){
            if(arr[mini] > arr[j])
                mini = j;
        }
        swap(arr[mini],arr[i]);
    }
}

void merge(int arr[],int l,int mid,int h){
    int merger[h-l+1];
    int i=l,j=mid+1;
    int k=0;
    while(i<=mid&&j<=h){
        if(arr[i]<arr[j])
            merger[k++] = arr[i++];
        else
            merger[k++] = arr[j++];
    }
    
    while(i<=mid)
        merger[k++] = arr[i++];
    while(j<=h)
        merger[k++] = arr[j++];
    
    for(int i=l,k=0;i<=h;i++,k++){
        arr[i]=merger[k];
    }
}

void merge_sort(int arr[],int l,int h){
    if(l<h){
        int mid = (l+h)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}

void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int j =i-1;
        int temp  = arr[i]; 
        while(j>=0 && arr[j] >temp){
            arr[j+1]= arr[j];
            j--;
        }
        j++;
        arr[j] = temp;
    }
}

int partition(int arr[],int l,int h){
    int pivot = arr[h];
    int i = l-1;
    for(int j=l;j<h;j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[h],arr[i]);
    return i;
}

void quick_sort(int arr[],int l,int h){
    if(l<h){
        int pi = partition(arr,l,h);
        quick_sort(arr,l,pi-1);
        quick_sort(arr,pi+1,h);
    }
}

// 1 5 2 3 4
// 0 1 2 3 4
int main()
{
    
    for(int t=1;t<=10;t++){
        int n = 100*t;
        int arr[n];
        for(int i=0;i<n;i++)
            arr[i] = rand()%100 + i;
            
        int *arr1=arr;
        clock_t start_t = clock();
        selection_sort(arr1,n);
        clock_t end_t = clock();
        double sst = ((double)(end_t - start_t)*1000)/CLOCKS_PER_SEC;
        
        
        arr1 = arr;
        start_t = clock();
        insertion_sort(arr1,n);
        end_t = clock();
        double ist = ((double)(end_t - start_t)*1000)/CLOCKS_PER_SEC;
        
        arr1 = arr;
        start_t = clock();
        merge_sort(arr1,0,n-1);
        end_t = clock();
        double mst = ((double)(end_t - start_t)*1000)/CLOCKS_PER_SEC;
        
        arr1 = arr;
        start_t = clock();
        quick_sort(arr1,0,n-1);
        end_t = clock();
        double qst = ((double)(end_t - start_t)*1000)/CLOCKS_PER_SEC;
        
        cout<<"for n = "<<n<<" selection_sort = "<<sst<<" insertion_sort = "<<ist<<" merge_sort = "<<mst<<" quick_sort = "<<qst<<endl<<endl;
        
    }
    
    // merge_sort(arr,0,9);
    // selection_sort(arr,n);
    // insertion_sort(arr,n);
    // quick_sort(arr,0,n-1);
    // for(int i=0;i<n;i++)
    //     cout<<arr[i]<<" ";
    return 0;
}

