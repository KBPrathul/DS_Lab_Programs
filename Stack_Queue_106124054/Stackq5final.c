//q5    Finding the celebrity in a 2D matrix

#include <stdio.h>
#include <limits.h>

int main() {
	int n,m;
	printf("Enter the number of rows: ");
	scanf("%d",&n);
	printf("Enter the number of columns: ");
	scanf("%d",&m);
	int nums[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("Enter value: ");
			scanf("%d",&nums[i][j]);
		}
	}
	int ans=0;
	for(int i=0;i<m;i++){
		int count=0;
		for(int j=0;j<n;j++){
			if(nums[j][i]==1){count++;}
		}
		if(count==n){ans=i;break;}
	}
	for(int i=0;i<m;i++){
		if(i!=ans && nums[ans][i]==1){ans=-1;}
	}
	printf("The celebrity is %d",ans);
	return 0;
}

/*Enter the number of rows: 3
Enter the number of columns: 3
Enter value: 1
Enter value: 1
Enter value: 0
Enter value: 0
Enter value: 1
Enter value: 0
Enter value: 0
Enter value: 1
Enter value: 1
The celebrity is 1*/
