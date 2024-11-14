#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binary_search(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

void find_nearest_elements(int arr[], int size, int target, int k, int result[]) {
    int pos = binary_search(arr, size, target);
    int left = pos - 1;
    int right = pos;
    int index = 0;

    while (k > 0) {
        if (left < 0) {
            result[index++] = arr[right++];
        } else if (right >= size) {
            result[index++] = arr[left--];
        } else {
            if (abs(arr[left] - target) <= abs(arr[right] - target)) {
                result[index++] = arr[left--];
            } else {
                result[index++] = arr[right++];
            }
        }
        k--;
    }
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int size, target, k;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));

    printf("Enter the array elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target value: ");
    scanf("%d", &target);

    printf("Enter the number of nearest elements to the target: ");
    scanf("%d", &k);

    int *result = (int *)malloc(k * sizeof(int));

    find_nearest_elements(arr, size, target, k, result);

    qsort(result, k, sizeof(int), compare);

    printf("The nearest elements are: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(arr);
    free(result);

    return 0;
}
