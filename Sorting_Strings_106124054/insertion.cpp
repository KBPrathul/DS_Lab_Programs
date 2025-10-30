//Insertion sort

#include <bits/stdc++.h>
using namespace std;

void printarr(vector<int>arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertionsort_iter(vector<int>arr,int comp){
    for(int i=1;i<arr.size();i++){
        int j=i-1;
        int curr=arr[i];
        while(j>=0){
            comp++;
            if(arr[j]>curr){
                arr[j+1]=arr[j];
                j--;
            }
            else{
                break;
            }
        }
        arr[j+1]=curr;
        printarr(arr);
    }
    cout<<"The number of comparisons is: "<<comp<<endl;
}

void insertionsort_rec(vector<int>arr,int comp,int i){
    if(i>=arr.size()){
        cout<<"The number of comparisons is: "<<comp<<endl;
        return;
    }
    int j=i-1;
    int curr=arr[i];
    while(j>=0){
        comp++;
        if(arr[j]>curr){
            arr[j+1]=arr[j];
            j--;
        }
        else{
            break;
        }
    }
    arr[j+1]=curr;
    printarr(arr);
    insertionsort_rec(arr,comp,i+1);
}

int main() {
    vector<int>arr1={1,2,3,4,5};
    vector<int>arr2={5,4,3,2,1};
    vector<int>arr3={2,3,1,5,4};
    insertionsort_iter(arr1,0);
    insertionsort_rec(arr1,0,1);
    insertionsort_iter(arr2,0);
    insertionsort_rec(arr2,0,1);
    insertionsort_iter(arr3,0);
    insertionsort_rec(arr3,0,1);
}

/*1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
The number of comparisons is: 4
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
The number of comparisons is: 4
4 5 3 2 1 
3 4 5 2 1 
2 3 4 5 1 
1 2 3 4 5 
The number of comparisons is: 10
4 5 3 2 1 
3 4 5 2 1 
2 3 4 5 1 
1 2 3 4 5 
The number of comparisons is: 10
2 3 1 5 4 
1 2 3 5 4 
1 2 3 5 4 
1 2 3 4 5 
The number of comparisons is: 6
2 3 1 5 4 
1 2 3 5 4 
1 2 3 5 4 
1 2 3 4 5 
The number of comparisons is: 6*/