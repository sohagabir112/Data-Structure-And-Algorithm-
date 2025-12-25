#include<iostream>
using namespace std;

// void insertionSort(int arr[], int n){
//     for(int i=1;i<n;i++)
//     {
//         int temp = arr[i];
//         int j = i-1;

//         while(j>=0 && arr[j]>temp)
//         {
//             arr[j+1] = arr[j];
//             j--;
//         }
//         arr[j+1] = temp;
//     }
// }

void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++)
    {
        int j = i;
        // while(j>=1)
        // {
        //     if(arr[j] >= arr[j-1]) break;
        //     else swap(arr[j],arr[j-1]);
        //     j--;
        // }

        while(j>=1 && arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

void printArray(int arr[], int n){
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter Array size: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<"Unsorted Array: ";
    printArray(arr,n);

    insertionSort(arr,n);
    cout<<"Sorted Array: ";
    printArray(arr,n);

    return 0;
}