#include<iostream>
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(int *arr,int low,int high){
    int pivot = arr[high];
    int i = (low-1);

    for(int j=low;j<high;j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

void quickSort(int *arr,int low,int high){
    if(low < high){
        int pi = partition(arr,low,high);

        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main(void){
    int arr[] = {10,7,8,9,1,53,5,6,11};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Unsorted Array : ";
    printArray(arr,n);
    quickSort(arr,0,n-1);
    cout<<"Sorted Array : ";
    printArray(arr,n);
    return 0;
}