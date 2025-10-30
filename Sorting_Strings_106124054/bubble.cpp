//Bubble sort

#include<bits/stdc++.h>
using namespace std;

void printarr(vector<int>arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubblesort_iter(vector<int>arr,int comp){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int flag=0;
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){swap(arr[j],arr[j+1]);flag=1;}
            comp++;
            printarr(arr);
        }
        if(flag==0){break;}
    }
    cout<<"The number of comparisons is: "<<comp<<endl;
}

void bubblesortoptimized_iter(vector<int>arr,int comp){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int flag=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){swap(arr[j],arr[j+1]);flag=1;}
            comp++;
            printarr(arr);
        }
        if(flag==0){break;}
    }
    cout<<"The number of comparisons is: "<<comp<<endl;
}

void bubblesort_rec(vector<int>arr,int comp, int i){
    int n=arr.size();
    if(i>=n){cout<<"The number of comparisons is: "<<comp<<endl;return;}
    int flag=0;
    for(int j=0;j<n-1;j++){
        if(arr[j]>arr[j+1]){swap(arr[j],arr[j+1]);flag=1;}
        comp++;
        printarr(arr);
    }
    if(flag==0){cout<<"The number of comparisons is: "<<comp<<endl;return;}
    i++;
    bubblesort_rec(arr,comp,i);
}

void bubblesortoptimized_rec(vector<int>arr,int comp, int i){
    int n=arr.size();
    if(i>=n){cout<<"The number of comparisons is: "<<comp<<endl;return;}
    int flag=0;
    for(int j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){swap(arr[j],arr[j+1]);flag=1;}
        comp++;
        printarr(arr);
    }
    if(flag==0){cout<<"The number of comparisons is: "<<comp<<endl;return;}
    i++;
    bubblesortoptimized_rec(arr,comp,i);
}

int main(){
    vector<int>arr1={1,2,3,4,5};
    vector<int>arr2={5,4,3,2,1};
    vector<int>arr3={2,3,1,5,4};
    bubblesort_iter(arr1,0);
    bubblesort_rec(arr1,0,0);
    bubblesort_iter(arr2,0);
    bubblesort_rec(arr2,0,0);
    bubblesort_iter(arr3,0);
    bubblesort_rec(arr3,0,0);
    bubblesortoptimized_iter(arr1,0);
    bubblesortoptimized_rec(arr1,0,0);
    bubblesortoptimized_iter(arr2,0);
    bubblesortoptimized_rec(arr2,0,0);
    bubblesortoptimized_iter(arr3,0);
    bubblesortoptimized_rec(arr3,0,0);
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
4 3 5 2 1 
4 3 2 5 1 
4 3 2 1 5 
3 4 2 1 5 
3 2 4 1 5 
3 2 1 4 5 
3 2 1 4 5 
2 3 1 4 5 
2 1 3 4 5 
2 1 3 4 5 
2 1 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
The number of comparisons is: 20
4 5 3 2 1 
4 3 5 2 1 
4 3 2 5 1 
4 3 2 1 5 
3 4 2 1 5 
3 2 4 1 5 
3 2 1 4 5 
3 2 1 4 5 
2 3 1 4 5 
2 1 3 4 5 
2 1 3 4 5 
2 1 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
The number of comparisons is: 20
2 3 1 5 4 
2 1 3 5 4 
2 1 3 5 4 
2 1 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
The number of comparisons is: 12
2 3 1 5 4 
2 1 3 5 4 
2 1 3 5 4 
2 1 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
The number of comparisons is: 12
1 2 3 4 5 
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
4 3 5 2 1 
4 3 2 5 1 
4 3 2 1 5 
3 4 2 1 5 
3 2 4 1 5 
3 2 1 4 5 
2 3 1 4 5 
2 1 3 4 5 
1 2 3 4 5 
The number of comparisons is: 10
4 5 3 2 1 
4 3 5 2 1 
4 3 2 5 1 
4 3 2 1 5 
3 4 2 1 5 
3 2 4 1 5 
3 2 1 4 5 
2 3 1 4 5 
2 1 3 4 5 
1 2 3 4 5 
The number of comparisons is: 10
2 3 1 5 4 
2 1 3 5 4 
2 1 3 5 4 
2 1 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
The number of comparisons is: 9
2 3 1 5 4 
2 1 3 5 4 
2 1 3 5 4 
2 1 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
1 2 3 4 5 
The number of comparisons is: 9*/