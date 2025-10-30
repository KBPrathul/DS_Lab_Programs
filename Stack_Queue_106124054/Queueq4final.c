//q4    Finding lowest lenght of subarray with sum greater than or equal to k

#include <stdio.h>
#include <limits.h>

int main() {
	int n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int nums[n];
	for(int i=0;i<n;i++){
		printf("Enter value: ");
		scanf("%d",&nums[i]);
	}
	int k;
	printf("Enter the value of k: ");
	scanf("%d",&k);
	int ans=INT_MAX;
	for (int i = 0; i < n; i++) {
        long sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            if (sum >= k) {
                if (j - i + 1 < ans){
                    ans = j - i + 1;
                }
                break;
            }
        }
    }
	if(ans==INT_MAX){printf("%d",-1);}
	else{printf("%d",ans);}
	return 0;
}

/*Enter the size of the array: 3
Enter value: 2
Enter value: -1
Enter value: 2
Enter the value of k: 3
Shortest subarray length: 3*/
