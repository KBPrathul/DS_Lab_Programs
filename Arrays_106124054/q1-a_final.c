//q1-a  Max element of array using tournament method

#include<stdio.h>

int max(int arr[],int left,int right){
    if(left==right){
        return arr[left];
    }
    else if(right-left==1){
        return arr[left]>arr[right]?arr[left]:arr[right];
    }
    else{
        int mid=(left+right)/2;
        int leftm=max(arr,left,mid);
        int rightm=max(arr,mid+1,right);
        return leftm>rightm?leftm:rightm;
    }
}

int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d",&arr[i]);
    }
    printf("Maximum = %d\n",max(arr,0,n-1));
    return 0;
}

/*Enter number of elements: 4
Enter element: 2
Enter element: 4
Enter element: 1
Enter element: 2
Maximum = 4*/