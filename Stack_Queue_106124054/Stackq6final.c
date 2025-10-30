//q6    Trapping rainwater

#include<stdio.h>

int min(int a,int b){
    if(a>b){return b;}
    else return a;
}

int main(){
    int arr[]={0,1,0,2,1,0,1,3,2,1,2,1};
    int n=12;
    int lmax=arr[0],rmax=arr[n-1];
    int ans=0;
    int left=0,right=n-1;
    while(left<right){
        if(arr[left]<=arr[right]){
            left++;
            if(arr[left]<lmax){ans+=(min(rmax,lmax)-arr[left]);}
            else{lmax=arr[left];}
        }
        else{
            right--;
            if(arr[right]<rmax){ans+=min(rmax,lmax)-arr[right];}
            else{rmax=arr[right];}
        }
    }
    printf("%d units of water are trapped.",ans);
}

/*6 units of water are trapped.*/
