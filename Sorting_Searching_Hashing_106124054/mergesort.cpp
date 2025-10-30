//Merge sort implementation

#include<bits/stdc++.h>
using namespace std;

int comp=0;

void printarr(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(vector<int>&arr, int low, int mid, int high){
    int i=low,j=mid+1;
    vector<int>temp;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
        comp++;
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=high){
        temp.push_back(arr[j]);
        j++;
    }
    for(int k=low;k<=high;k++){
        arr[k]=temp[k-low];
    }
    printarr(arr);
    cout<<"The number of comparisons is: "<<comp<<endl;
}

void mergesort(vector<int>&arr, int low, int high){
    if(low==high){return;}
    int mid=(low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
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
    mergesort(arr,0,n-1);
}

/*Enter the size of the array: 5
Enter element: 3
Enter element: 2
Enter element: 5
Enter element: 1
Enter element: 4
2 3 5 1 4 
The number of comparisons is: 1
2 3 5 1 4 
The number of comparisons is: 3
2 3 5 1 4 
The number of comparisons is: 4
1 2 3 4 5
The number of comparisons is: 8*/