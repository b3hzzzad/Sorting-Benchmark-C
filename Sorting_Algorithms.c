#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int size);
void selection_sort(int arr[], int size);
void insertion_sort(int arr[], int size);
void merge_sort(int arr[], int size);
void merge(int arr[], int left[], int left_size, int right[], int right_size);

int main(void) {

    printf("===========================================\n");
    printf("        SORTING ALGORITHM BENCHMARK\n");
    printf("===========================================\n\n");

    printf("Enter array size: ");

    int size = 0;
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    int *arr = malloc(size * sizeof(int));
    int *temp = malloc(size * sizeof(int));

    if (!arr || !temp) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < size; i++)
        arr[i] = rand() % size;

    printf("\nGenerating random array...\n");
    printf("Running benchmarks...\n\n");

    clock_t start, end;
    double bubble_t, selection_t, insertion_t, merge_t;

    // Bubble Sort
    for (int i = 0; i < size; i++) temp[i] = arr[i];
    start = clock();
    bubble_sort(temp, size);
    end = clock();
    bubble_t = (double)(end - start) / CLOCKS_PER_SEC;

    // Selection Sort
    for (int i = 0; i < size; i++) temp[i] = arr[i];
    start = clock();
    selection_sort(temp, size);
    end = clock();
    selection_t = (double)(end - start) / CLOCKS_PER_SEC;

    // Insertion Sort
    for (int i = 0; i < size; i++) temp[i] = arr[i];
    start = clock();
    insertion_sort(temp, size);
    end = clock();
    insertion_t = (double)(end - start) / CLOCKS_PER_SEC;

    // Merge Sort
    for (int i = 0; i < size; i++) temp[i] = arr[i];
    start = clock();
    merge_sort(temp, size);
    end = clock();
    merge_t = (double)(end - start) / CLOCKS_PER_SEC;

    // Results Table
    printf("-------------------------------------------\n");
    printf(" Algorithm          |     Time (seconds)\n");
    printf("-------------------------------------------\n");

    printf(" Bubble Sort        |     %.6f\n", bubble_t);
    printf(" Selection Sort     |     %.6f\n", selection_t);
    printf(" Insertion Sort     |     %.6f\n", insertion_t);
    printf(" Merge Sort         |     %.6f\n", merge_t);

    printf("-------------------------------------------\n\n");

    printf("Done.\n");

    free(arr);
    free(temp);

    return 0;
}



void bubble_sort(int arr[], int size){

	//repeat the proccess with the size of array so all the elements are sorted
	for(int k = 0; k < size -1; k++){
		
		//swapping the elements to right
		for(int i = 0; i < size -1; i++){
			if(arr[i] > arr[i + 1]){
				int temp = arr[i];
				arr[i] = arr [i + 1];
				arr[i + 1] = temp;
		
			}
		}
	}

}

void selection_sort(int arr[], int size){

	for (int x = 0; x < size - 1; x++) {

        int smallest_index = x;

        // find the smallest element in the rest of the array
        for (int i = x + 1; i < size; i++) {
            if (arr[i] < arr[smallest_index]) {
                smallest_index = i;
            }
        }

        // swap the smallest with the current position
        int temp = arr[x];
        arr[x] = arr[smallest_index];
        arr[smallest_index] = temp;

	}

}

void insertion_sort(int arr[], int size){

	for (int i = 0; i < size; i++){

		int key = arr[i];
		int j = i - 1;

		while( j >= 0 && arr[j] > key){

		arr[j + 1] = arr[j];
		j--;

		}
		arr[j + 1] = key;
	}
}

void merge(int arr[], int left[], int left_size, int right[], int right_size) {

    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < left_size) arr[k++] = left[i++];
    while (j < right_size) arr[k++] = right[j++];
}

void merge_sort(int arr[], int size) {

    if (size <= 1)
        return;

    int mid = size / 2;

    int left[mid];
    int right[size - mid];

    for (int i = 0; i < mid; i++)
        left[i] = arr[i];

    for (int i = mid; i < size; i++)
        right[i - mid] = arr[i];

    merge_sort(left, mid);
    merge_sort(right, size - mid);

    merge(arr, left, mid, right, size - mid);
}

