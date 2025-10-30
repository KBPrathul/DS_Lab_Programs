//q1    Maximum product of triplet

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN,min1=INT_MAX,min2=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]>max1){
            max1=arr[i];
            max2=max1;
            max3=max2;
        }
        else if(arr[i]>max2){
            max2=arr[i];
            max3=max2;
        }
        else if(arr[i]>max3){
            max3=arr[i];
        }
        if(arr[i]<min1){
            min1=arr[i];
            min2=min1;
        }
        else if(arr[i]<min2){
            min2=arr[i];
        }
    }
    cout<<max(max1*max2*max3,max1*min1*min2);
}

/*Enter number of elements: 5
Enter number: 4
Enter number: 6
Enter number: -4
Enter number: -5
Enter number: 2
120*/