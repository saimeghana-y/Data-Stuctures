#include <iostream>
using namespace std;

void heapify(int arr[],int n,int i){
    int b = i;
    
    if((2 * i + 1 < n) && arr[2 * i + 1] > arr[b])
        b = 2 * i + 1;
    if((2 * i + 2 < n) && arr[2 * i + 2] > arr[b])
        b = 2 * i + 2;
    if(b != i){
        swap(arr[i],arr[b]);
        heapify(arr,n,b);
    }
}

void heapsort(int arr[], int n){
    for(int i = n/2 - 1;i >= 0;i--)
        heapify(arr,n,i);
        
    for(int i = n - 1;i >= 0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }    
}


int main()
{
    int arr[]={0,0,1,123,45,23};
    heapsort(arr,6);
    for (int i=0; i<6; ++i) 
        cout << arr[i] << " ";

    return 0;
}
