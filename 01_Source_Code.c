#include <stdio.h>

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int temp[100];

    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= high)
        temp[k++] = a[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        a[i] = temp[k];
}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            int t = a[i]; a[i] = a[j]; a[j] = t;
        }
    }

    int t = a[i + 1];
    a[i + 1] = a[high];
    a[high] = t;
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main() {
    int data[] = {324, 125, 456, 218, 102, 389, 275, 147};
    int n = 8;
    int mergeData[8], quickData[8];

    for (int i = 0; i < n; i++) {
        mergeData[i] = data[i];
        quickData[i] = data[i];
    }

    printf("Input: ");
    printArray(data, n);

    mergeSort(mergeData, 0, n - 1);
    printf("Merge Sort Output: ");
    printArray(mergeData, n);

    quickSort(quickData, 0, n - 1);
    printf("Quick Sort Output: ");
    printArray(quickData, n);

    return 0;
}
