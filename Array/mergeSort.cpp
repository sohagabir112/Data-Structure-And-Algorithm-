#include<iostream>
using namespace std;

void merge(int arr[], int lb, int mid, int ub){
    int i = lb;
    int j = mid+1;
    int k = lb;
    int brr[ub+1];
    while(i <= mid && j <= ub)
    {
        if(arr[i] <= arr[j])
        {
            brr[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            brr[k] = arr[j];
            j++;
            k++;
        }
    }

    while(j <= ub)
    {
        brr[k] = arr[j];
        j++;
        k++;
    }
        
    while(i <= mid)
    {
        brr[k] = arr[i];
        i++;
        k++;
    }

    
    for(int m = lb; m <= ub; m++) {
        arr[m] = brr[m];
    }
} 

void mergeSort(int arr[], int lb, int ub){
    if(lb<ub)
    {
        int mid = (lb+ub)/2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid+1, ub);
        merge(arr, lb, mid, ub);
    }
}



void printArray(int arr[], int n){
    for(int i=0;i<n;i++)
         cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter Array Size: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin >>arr[i];

    cout<<"Unsorted Array: ";
    printArray(arr,n);

    mergeSort(arr, 0, n-1);
    cout<<"Sorted Array: ";
    printArray(arr, n);

    return 0;
}