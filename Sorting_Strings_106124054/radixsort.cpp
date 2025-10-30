//Radix sort

#include <bits/stdc++.h>
using namespace std;

void printarr(vector<int>arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<vector<int>>helper(vector<int>&arr,int exp){
    vector<vector<int>>bin(10);
    for(int i=0;i<arr.size();i++){
        int digit=(arr[i]/exp)%10;
        bin[digit].push_back(arr[i]);
    }
    return bin;
}

void radixsort(vector<int>& arr){
    if(arr.empty()) return;
    int maxel=INT_MIN;
    for(int num:arr){
        maxel=max(maxel,abs(num));
    }
    for(int exp=1;maxel/exp>0;exp*=10){
        vector<vector<int>>bin=helper(arr,exp);
        int ptr=0;
        for(int i=0;i<bin.size();i++){
            for(int j=0;j<bin[i].size();j++){
                arr[ptr++]=bin[i][j];
            }
        }
        printarr(arr);
    }
}

int main(){
    vector<int>arr1={13,22,35,49,50};
    vector<int>arr2={50,49,35,22,13};
    vector<int>arr3={22,35,13,50,49};
    radixsort(arr1);
    cout<<endl;
    radixsort(arr2);
    cout<<endl;
    radixsort(arr3);
    cout<<endl;
}

/*50 22 13 35 49 
13 22 35 49 50 

50 22 13 35 49 
13 22 35 49 50 

50 22 13 35 49 
13 22 35 49 50 */
