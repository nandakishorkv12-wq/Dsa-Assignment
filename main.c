#include <stdio.h>

int mergeComparisons = 0, quickComparisons = 0;

void merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0, temp[20];

    while (i <= mid && j <= high)
    {
        mergeComparisons++;

        if (a[i] < a[j])
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

    printf("After merge: ");

    for (i = low; i <= high; i++)
        printf("%d ", a[i]);

    printf("\n");
}

void mergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[high], i = low - 1, j, temp;

    for (j = low; j < high; j++)
    {
        quickComparisons++;

        if (a[j] < pivot)
        {
            i++;

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    printf("Pivot %d: ", pivot);

    for (j = low; j <= high; j++)
        printf("%d ", a[j]);

    printf("\n");

    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main()
{
    int a[] = {324, 125, 456, 218, 102, 389, 275, 147};
    int b[] = {324, 125, 456, 218, 102, 389, 275, 147};

    int n = 8, i;

    printf("MERGE SORT\n");

    mergeSort(a, 0, n - 1);

    printf("Final: ");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nComparisons = %d\n", mergeComparisons);

    printf("\nQUICK SORT\n");

    quickSort(b, 0, n - 1);

    printf("Final: ");

    for (i = 0; i < n; i++)
        printf("%d ", b[i]);

    printf("\nComparisons = %d\n", quickComparisons);

    return 0;
}
