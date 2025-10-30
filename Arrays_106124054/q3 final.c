//q3    Occurences of given element

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
	int target;
	printf("Enter the target:");
	scanf("%d",&target);
	int count=0;
	int c=0;
	for(int i=0;i<n;i++){
		if(target==arr[i]){
		count++;
		}
		if(!c && count==1){
			printf("%d",i);
			c++;
		}
	}
	printf("%d\n",count);
	return 0;
}

/*Enter size of array: 6
Enter element:1
Enter element:3
Enter element:2
Enter element:1
Enter element:3
Enter element:1
Enter the target:1
3*/