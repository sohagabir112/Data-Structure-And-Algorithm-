#include<iostream>
using namespace std;

int partion(int arr[], int lb, int ub){
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while(start<end)
    {
        while(arr[start] <= pivot)  start++;
        while(arr[end] > pivot) end--;

        if(start<end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            //swap(arr[start], arr[end]);
        }
    }
    int temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;
    //swap(arr[lb], arr[end]);

    return end;
}

void quickSort(int arr[], int lb, int ub){
    if(lb<ub)
    {
        int loc = partion(arr, lb, ub);
        quickSort(arr, lb, loc-1);
        quickSort(arr, loc+1, ub);
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

    quickSort(arr,0, n-1);
    cout<<"Sorted Array: ";
    printArray(arr, n);

    return 0;
}