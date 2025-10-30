//Heap sort implementation

#include<bits/stdc++.h>
using namespace std;

int comp=0;

void printarr(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void heapify(vector<int>& arr,int n,int i){
    int largest=i;
    int lc=2*i+1;
    int rc=2*i+2;
    if(lc<n){
        comp++;
        if(arr[lc]>arr[largest]){
            largest=lc;
        }
    }
    if(rc<n){
        comp++;
        if(arr[rc]>arr[largest]){
            largest=rc;
        }
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr, n, largest);
    }
    printarr(arr);
    cout<<"The number of comparisons is: "<<comp<<endl;
}

void buildmaxheap(vector<int>& arr){
    int n=arr.size();
    for(int i=(n/2)-1;i>=0;i--){
        heapify(arr, n, i);
    }
}

void heapSort(vector<int>&arr){
    int n=arr.size();
    buildmaxheap(arr);
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

int main(){
    cout<<"Enter the size of the array: ";
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cout<<"Enter element: ";
        cin>>arr[i];
    }
    heapSort(arr);
    return 0;
}

/*Enter the size of the array: 5
Enter element: 3
Enter element: 2
Enter element: 5
Enter element: 1
Enter element: 4
3 4 5 1 2 
The number of comparisons is: 2
3 4 5 1 2 
The number of comparisons is: 2
5 4 3 1 2 
The number of comparisons is: 4
5 4 3 1 2
The number of comparisons is: 4
4 2 3 1 5
The number of comparisons is: 7
4 2 3 1 5
The number of comparisons is: 7
3 2 1 4 5
The number of comparisons is: 9
3 2 1 4 5
The number of comparisons is: 9
2 1 3 4 5
The number of comparisons is: 10
2 1 3 4 5
The number of comparisons is: 10
1 2 3 4 5
The number of comparisons is: 10*/