//q4    Spiral print of elements of matrix

#include <stdio.h>

int main() {
    int n, m;
    printf("How many rows do you want? ");
    scanf("%d", &n);
    printf("How many columns do you want? ");
    scanf("%d", &m);
    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Enter element: ");
            scanf("%d", &arr[i][j]);
        }
    }
    int up = 0, down = n - 1;
    int left = 0, right = m - 1;
    while (left <= right && up <= down) {
        for (int i = left; i <= right; i++) {
            printf("%d ", arr[up][i]);
        }
        up++;
        if (up > down){
            break;
        }
        for (int i = up; i <= down; i++) {
            printf("%d ", arr[i][right]);
        }
        right--;
        if (left > right){
            break;
        }

        for (int i = right; i >= left; i--) {
            printf("%d ", arr[down][i]);
        }
        down--;
        if (up > down){
            break;
        }

        for (int i = down; i >= up; i--) {
            printf("%d ", arr[i][left]);
        }
        left++;
    }
    return 0;
}

/*How many rows do you want? 3
How many columns do you want? 3
Enter element: 1
Enter element: 2
Enter element: 3
Enter element: 4
Enter element: 5
Enter element: 6
Enter element: 7
Enter element: 8
Enter element: 9
1 2 3 6 9 8 7 4 5 */