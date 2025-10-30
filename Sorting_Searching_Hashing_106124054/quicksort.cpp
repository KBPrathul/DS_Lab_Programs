// Quick sort implementation

#include<bits/stdc++.h>
using namespace std;

int comp=0;

void printarr(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int helper1(vector<int>&arr, int low, int high){
    int curr=arr[low],i=low,j=high;
    while(i<j){
        while(i<=j && arr[i]<=curr){i++;comp++;}
        while(j>=low && arr[j]>curr){j--;comp++;}
        if(i<j){swap(arr[i],arr[j]);}
    }
    swap(arr[low],arr[j]);
    printarr(arr);
    cout<<"The number of comparisons is: "<<comp<<endl;
    return j;
}

int helper2(vector<int>&arr, int low, int high){
    int mid = low + (high - low) / 2;
    swap(arr[low], arr[mid]);
    int curr=arr[low],i=low,j=high;
    while(i<j){
        while(i<=j && arr[i]<=curr){i++;comp++;}
        while(j>=low && arr[j]>curr){j--;comp++;}
        if(i<j){swap(arr[i],arr[j]);}
    }
    swap(arr[low],arr[j]);
    printarr(arr);
    cout<<"The number of comparisons is: "<<comp<<endl;
    return j;
}

int helper3(vector<int>&arr, int low, int high){
    swap(arr[low], arr[high]);
    int curr=arr[low],i=low,j=high;
    while(i<j){
        while(i<=j && arr[i]<=curr){i++;comp++;}
        while(j>=low && arr[j]>curr){j--;comp++;}
        if(i<j){swap(arr[i],arr[j]);}
    }
    swap(arr[low],arr[j]);
    printarr(arr);
    cout<<"The number of comparisons is: "<<comp<<endl;
    return j;
}

void quicksort(vector<int>&arr, int low, int high){
    if(low<high){
        int temp=helper1(arr,low,high);
        quicksort(arr,low,temp-1);
        quicksort(arr,temp+1,high);
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
    quicksort(arr,0,n-1);
}

/*Enter the size of the array: 5
Enter element: 5
Enter element: 4
Enter element: 3
Enter element: 2
Enter element: 1
1 4 3 2 5 
The number of comparisons is: 5
1 4 3 2 5 
The number of comparisons is: 9
1 2 3 4 5 
The number of comparisons is: 12
1 2 3 4 5
The number of comparisons is: 14*/