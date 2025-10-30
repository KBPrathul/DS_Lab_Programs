//q1-b      Max and 2nd Max element of an array using tournament method

#include <stdio.h>
#include<limits.h>

struct MaxPair{
    int max1;
    int max2;
};

struct MaxPair findMax(int arr[], int left, int right) {
    struct MaxPair result;
    if(left==right){
        result.max1=arr[left];
        result.max2=INT_MIN;
        return result;
    }
    else if(right-left==1){
        if(arr[left]>arr[right]){
            result.max1=arr[left];
            result.max2=arr[right];
        }
        else{
            result.max1=arr[right];
            result.max2=arr[left];
        }
        return result;
    }
    int mid=(left+right)/2;
    struct MaxPair leftPair=findMax(arr,left,mid);
    struct MaxPair rightPair=findMax(arr,mid+1,right);
    if(leftPair.max1>rightPair.max1){
        result.max1=leftPair.max1;
        result.max2=(leftPair.max2>rightPair.max1)?leftPair.max2:rightPair.max1;
    }
    else{
        result.max1=rightPair.max1;
        result.max2=(rightPair.max2>leftPair.max1)?rightPair.max2:leftPair.max1;
    }
    return result;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    if(n<2){
        printf("At least 2 elements are needed.\n");
    }
    else{
        int arr[n];
        for(int i=0;i<n;i++){
            printf("Enter element: ");
            scanf("%d",&arr[i]);
        }
        struct MaxPair result=findMax(arr, 0, n - 1);
        printf("Largest = %d\n",result.max1);
        printf("Second Largest = %d\n",result.max2);
        return 0;
    }
}

/*Enter number of elements: 5
Enter element: 3
Enter element: 4
Enter element: 1
Enter element: 7
Enter element: 2
Largest = 7
Second Largest = 4*/