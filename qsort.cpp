#include <stdio.h>
#include <stdlib.h>

void swap_int(int* a, int* b) {
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void insertion_sort(int arr[], int num) {
    int i,j;
    int tmp;
    for(i = 1; i < num; i++) {
        tmp = arr[i];
        for(j = i; j > 0 && arr[j - 1] > tmp; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;
    }
}


// a way to define quicksort pivot
int median3(int arr[], int left, int right) {
    int center = (left + right) / 2;
    if (arr[left] > arr[center])
        swap_int(&arr[left], &arr[center]);
    if (arr[left] > arr[right])
        swap_int(&arr[left], &arr[right]);
    if (arr[center] > arr[right])
        swap_int(&arr[center], &arr[right]);
    swap_int(&arr[center], &arr[right - 1]);
    return arr[right - 1];
}

void quick_sort(int arr[],int left,int right) {
    int i = 0;
    int j = 0;
    int pivot = 0;
    const int cutoff = 3;
    if (left + cutoff <= right) {
        // Make sure pivot > arr[right] && pivot < arr[left]
        pivot = median3(arr, left, right);
        i = left;
        j = right - 1;
        while (true) {
            // <= OR <
            while(arr[++i] <= pivot) {;}
            // >= OR >
            while(arr[--j] >= pivot) {;}
            if (i < j)
                swap_int(&arr[i], &arr[j]);
            else
                break;
        }
        // arr[right - 1] == pivot
        swap_int(&arr[i], &arr[right - 1]);
        quick_sort(arr, left, i - 1);
        quick_sort(arr, i + 1, right);
    }
    else {
        insertion_sort(arr+left, right - left + 1);
    }
}
