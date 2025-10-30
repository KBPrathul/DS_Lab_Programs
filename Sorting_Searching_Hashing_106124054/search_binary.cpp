//Binary search implementation

#include<bits/stdc++.h>
using namespace std;

int binarysearchrec(vector<int>&arr, int left, int right, int target){
    if(left>right){return -1;}
    int mid=(left+right)/2;
    if(arr[mid]>target){
        return binarysearchrec(arr,left,mid-1,target);
    }
    else if(arr[mid]<target){
        return binarysearchrec(arr,mid+1,right,target);
    }
    else{
        return mid;
    }
}

int binarysearchiter(vector<int>&arr, int target){
    int left=0,right=arr.size()-1;
    int index=-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]>target){
            right=mid-1;
        }
        else if(arr[mid]<target){
            left=mid+1;
        }
        else{
            index=mid;
            break;
        }
    }
    return index;
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
    int target;
    cout<<"Enter the target element: ";
    cin>>target;
    cout<<binarysearchiter(arr,target)<<endl;
    cout<<binarysearchrec(arr,0,n-1,target)<<endl;
}

/*Enter the size of the array: 5
Enter element: 1
Enter element: 2
Enter element: 3
Enter element: 4
Enter element: 5
Enter the target element: 4
3
3*/