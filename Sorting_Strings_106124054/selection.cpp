//Selection sort

#include<bits/stdc++.h>
using namespace std;

void printarr(vector<int>arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void selectionsort_iter(vector<int>arr,int comp){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int min=arr[i];
        int minindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<min){min=arr[j];minindex=j;}
            comp++;
        }
        swap(arr[minindex],arr[i]);
        printarr(arr);
    }
    cout<<"The number of comparisons is: "<<comp<<endl;
}

void selectionsort_rec(vector<int>arr,int comp, int i){
    int n=arr.size();
    if(i>=n-1){cout<<"The number of comparisons is: "<<comp<<endl;return;}
    int min=arr[i],minindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<min){min=arr[j];minindex=j;}
            comp++;
        }
        swap(arr[minindex],arr[i]);
        printarr(arr);
    i++;
    selectionsort_rec(arr,comp,i);
}

int main(){
    vector<int>arr1={1,2,3,4,5};
    vector<int>arr2={5,4,3,2,1};
    vector<int>arr3={2,3,1,5,4};
    selectionsort_iter(arr1,0);
    selectionsort_rec(arr1,0,0);
    selectionsort_iter(arr2,0);
    selectionsort_rec(arr2,0,0);
    selectionsort_iter(arr3,0);
    selectionsort_rec(arr3,0,0);
}

/*1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
The number of comparisons is: 10
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
The number of comparisons is: 10
1 4 3 2 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
The number of comparisons is: 10
1 4 3 2 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
The number of comparisons is: 10
1 3 2 5 4 
1 2 3 5 4 
1 2 3 5 4 
1 2 3 4 5 
1 2 3 4 5 
The number of comparisons is: 10
1 3 2 5 4 
1 2 3 5 4 
1 2 3 5 4 
1 2 3 4 5 
The number of comparisons is: 10*/