//q6    Dividing array into 2 equal parts

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
	if(n<=1){
		printf("Yes");
	}
	else{
		int sum=0;
		for(int i=0;i<n;i++){
			sum+=arr[i];
		}
		int target=sum/2;
		int sum2=0;
		int truth=0;
		for(int i=0;i<n;i++){
			sum2+=arr[i];
			if(sum2==target){
				printf("Yes");
				truth=1;
				break;
			}
		}
		if(!truth){
			printf("No");
		}
	}
	return 0;
}

/*Enter size of array: 5
Enter element:10
Enter element:20
Enter element:10
Enter element:10
Enter element:50
Yes*/