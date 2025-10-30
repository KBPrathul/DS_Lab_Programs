//q5    Disaster relief rescue

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
	for(int i=1;i<n;i+=2){
	sum+=arr[i];
	}
	printf("%d\n",sum);
	return 0;
}

/*Enter size of array: 6
Enter element:10
Enter element:20
Enter element:30
Enter element:40
Enter element:50
Enter element:60
120*/