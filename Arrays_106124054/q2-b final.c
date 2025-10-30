//q2-b    Recursive sum of elements in array

#include<stdio.h>

int sum(int ind,int n,int s,int arr[]){
	if(ind>=n){
		return s;
	}
	s+=arr[ind];
	sum(ind+1,n,s,arr);
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
	printf("%d\n",sum(0,n,0,arr));
	return 0;
}

/*Enter size of array: 4
Enter element:1
Enter element:3
Enter element:4
Enter element:5
13*/