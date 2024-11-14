#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int low, int mid, int high) {
    int n = high - low + 1;
    int temp[n];
    int left = low;
    int right = mid + 1;
    int i = 0;

    // Merging the two halves into temp array
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[i++] = arr[left++];
        } else {
            temp[i++] = arr[right++];
        }
    }

    // Copy remaining elements of the left half, if any
    while (left <= mid) {
        temp[i++] = arr[left++];
    }

    // Copy remaining elements of the right half, if any
    while (right <= high) {
        temp[i++] = arr[right++];
    }

    // Copy the merged subarray back to the original array
    for (i = 0; i < n; i++) {
        arr[low + i] = temp[i];
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low >= high) return;
    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);
    printArr(arr, n);

    return 0;
}
