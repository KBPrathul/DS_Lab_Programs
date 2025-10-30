//q7-b    Rotation of elements of array using recursion

#include<stdio.h>

void rec(int ind, int n, int k, int arr[],int ans[]){
	if(ind>=n){
	return;
	}
	ans[(ind+k)%n]=arr[ind];
	rec(ind+1,n,k,arr,ans);
}


int main(){
	int n;
	printf("Enter size of array: ");
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
	printf("Enter element:");
	scanf("%d",&arr[i]);
	}
	int k;
	printf("How many digits to rotate by?");
	scanf("%d",&k);
	int ans[n];
	rec(0,n,k,arr,ans);
	for(int i=0;i<n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}

/*Enter size of array: 5
Enter element:1
Enter element:2
Enter element:3
Enter element:4
Enter element:5
How many digits to rotate by?2
4 5 1 2 3 */