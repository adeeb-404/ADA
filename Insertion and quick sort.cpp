#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp = arr[i],j=i-1;
        while(j>=0&&arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

void print(int arr[],int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void is(){
    for(int t=1;t<11;t++){
        int n=100*t;
        int arr[n];
        for(int i=0;i<10;i++)
            arr[i] = rand()%100 +i;
        clock_t start_t = clock();
        insertion_sort(arr,n);
        clock_t end_t = clock();
        
        double ist = (((double)(end_t - start_t))*1000)/CLOCKS_PER_SEC;
        cout<<n<<" - "<<ist<<endl;
    }
}

int partition(int arr[],int l ,int h){
    int pivot = arr[h];
    int i = l-1;
    for(int j=l;j<h;j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[h]);
    return i;
}

void quick_sort(int arr[],int l,int h){
    if(l<h){
        int pi = partition(arr,l,h);
        quick_sort(arr,l,pi-1);
        quick_sort(arr,pi+1,h);
    }
}

void qs(){
    for(int t=1;t<11;t++){
        int n=100*t;
        int arr[n];
        for(int i=0;i<n;i++)
            arr[i] = rand()%10 +i;
        
        clock_t start_t = clock();
        quick_sort(arr,0,n-1);
        clock_t end_t = clock();
        
        double qst = (((double)(end_t - start_t))*1000)/CLOCKS_PER_SEC;
        
        cout<<n<<" - "<<qst<<endl;
    }
}

int main()
{
    
    is();
    cout<<"----------------------------------------------------------------------\n\n";
    qs();
    
    return 0;
}

