#include<iostream>
using namespace std;

// void selectionSort(int arr[], int n){
//     for(int i=0;i<n-1;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(arr[j]<arr[i])
//             {
//                 int temp = arr[j];
//                 arr[j] = arr[i];
//                 arr[i] = temp;
//             }    
//         }
//     }
// }

// void selectionSort(int arr[], int n){
//     for(int i=0;i<n-1;i++)
//     {
//         int min = i;
//         for(int j=i+1;j<n;j++)
//         {
//             if(arr[j]<arr[i]) min = j;
//         }

//         if(min != i) 
//         {
//             // int temp = arr[i];
//             // arr[i] = arr[min];
//             // arr[min] = temp;
//             swap(arr[i],arr[min]);
//         }
//     }
// }

void selectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++)
    {
        int min = INT_MAX;
        int mindex = -1;
        for(int j=i;j<n;j++)
        {
            if(arr[j]<min)
            {
                min = arr[j];
                mindex = j;    
            }    
        }
        swap(arr[i],arr[mindex]);
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

    selectionSort(arr,n);
    cout<<"Sorted Array: ";
    printArray(arr, n);

    return 0;
}