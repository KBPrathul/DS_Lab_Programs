//q2-a    Iterative sum of elements in array

#include<stdio.h>

int main(){
	int n;
	printf("Enter size of array: ");
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
	printf("Enter element:");
	scanf("%d",&arr[i]);
	}
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	printf("%d\n",sum);
	return 0;
}

/*Enter size of array: 4
Enter element:1
Enter element:3
Enter element:4
Enter element:5
13*/