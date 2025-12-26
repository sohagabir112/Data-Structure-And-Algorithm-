#include<iostream>
using namespace std;

void sellSort(int arr[], int n){
    for(int gap=n/2;gap>=1; gap /=2)
    {
        for(int j=gap; j<n;j++)
        {
            for(int i = j-gap;i>=0;i-=gap)
            {
                if(arr[i+gap] > arr[i]) break;
                else swap(arr[i+gap], arr[i]);
            }
        }
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

    sellSort(arr, n);
    cout<<"Sorted Array: ";
    printArray(arr, n);

    return 0;
}