//q1-c    Dynamic memory allocation

#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int* ptr=(int *)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        printf("Enter element: ");
        scanf("%d",&ptr[i]);
    }
    for(int i = 0; i < n; i++){
        printf("%d ",ptr[i]);
    }
    return 0;
}

/*Enter number of elements: 4
Enter element: 1
Enter element: 2
Enter element: 3
Enter element: 4
1 2 3 4 */