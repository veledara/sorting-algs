#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

void selectionSort(int *array, int size);
void bubbleSort(int *array, int size);
void bubbleSortWithIverson(int *array, int size);
void insertionSort(int *array, int size);
void binaryInsertionSort(int *array, int size);
void countSort(int array[], int n, int exp);
void radixSort(int array[], int size);
void mergeSort(int array[], int left, int righ);
void quickSortHoare(int *array, int left, int right);
void quickSortLomuto(int array[], int low, int high);
void heapSort(int arr[], int n);

#endif // SORTING_ALGORITHMS_H