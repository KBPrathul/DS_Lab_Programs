//Linear search implementation

#include<bits/stdc++.h>
using namespace std;

int linearsearchrec(vector<int>&arr, int i, int target){
    if(i>=arr.size()){return -1;}
    if(arr[i]==target){
        return i;
    }
    else{
        return linearsearchrec(arr,i+1,target);
    }
}

int linearsearchiter(vector<int>&arr, int target){
    int index=-1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==target){
            index=i;
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
    cout<<linearsearchiter(arr,target)<<endl;
    cout<<linearsearchrec(arr,0,target)<<endl;
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