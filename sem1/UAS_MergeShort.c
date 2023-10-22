#include <stdio.h>
#include <math.h>

void merge(int arr[], int left, int middle, int right) {
    // Determine the number of elements in each part of the array
    int n1 = middle - left + 1;
    int n2 = right - middle;
    
    // Create new arrays L and R to store the parts of the 'arr' array
    int L[n1];
    int R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];
    
    int i = 0, j = 0, k = left;
    
    // Merge the two sorted parts L and R back into 'arr' while sorting
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // If there are elements in L or R that haven't been merged, add them to 'arr'
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// The mergeSort function is used to sort an array using the merge sort method
void mergeSort(int arr[], int left, int right) {
    // If the elements in 'arr' from the left are smaller than those from the right, divide the array
    if (left < right) {
        // Find the middle value of the array to be sorted
        int middle = left + (right - left) / 2;

        // Call mergeSort for the left part of the array
        mergeSort(arr, left, middle);

        // Call mergeSort for the right part of the array
        mergeSort(arr, middle + 1, right);

        // Merge the left and right parts that are already sorted into one sorted array
        merge(arr, left, middle, right);
    }
}

int main() {
    printf("\033[2J\033[1;1H");  // Clear the console screen.
    unsigned int nim = 2602225201;
    int x = ceil((float)((nim + 1) % nim) / 2) * 10;
    int arr[6] = { 15, 8, 10, x, 17, 4 };
    
    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);
    
    mergeSort(arr, 0, n - 1);

    printf("Sorted array (ascending): \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    puts("\n");

    return 0;
}