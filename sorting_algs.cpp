#include <iostream>
#include <stdio.h>
#include <string.h>

// сортировка выбором
void selectionSort(int *array, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int min_index = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (array[j] < array[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            std::swap(array[i], array[min_index]);
        }
    }
}

// сортировка пузырьком
void bubbleSort(int *array, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (array[j] > array[j + 1])
            {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

// сортировка пузырьком с условием Айверсона 1
void bubbleSortWithIverson(int *array, int size)
{
    int k = 0;
    for (int i = 0; i < size - 1; ++i)
    {
        k = 0;
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (array[j] > array[j + 1])
            {
                std::swap(array[j], array[j + 1]);
                k = 1;
            }
        }
        if (k == 0)
        {
            return;
        }
    }
}

// сортировка простыми вставками
void insertionSort(int *array, int size)
{
    int temp, key, count = 0;
    bool on_right_place;
    for (int i = 0; i < size - 1; ++i)
    {
        key = i + 1;
        temp = array[key];
        on_right_place = true;
        for (int j = i + 1; j > 0; --j)
        {
            if (temp < array[j - 1])
            {
                array[j] = array[j - 1];
                key = j - 1;
                on_right_place = false;
            }
        }
        array[key] = temp;
        if (on_right_place)
        {
            ++count;
        }
    }
}

// сортировка бинарными вставками
void binaryInsertionSort(int *array, int size)
{
    int len, key, right, left, mid;
    for (int i = 0; i < size; ++i)
    {
        key = array[i];
        len = i - 1;
        left = 0;
        right = i - 1;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (array[mid] > array[i])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        while (left <= len)
        {
            std::swap(array[len], array[len + 1]);
            --len;
        }
        array[len + 1] = key;
    }
}

int getMax(const int array[], int n)
{
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

void countSort(int *array, int size)
{
    return;
}

void countSortForRadix(int array[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[(array[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        array[i] = output[i];
}

// цифровая сортировка
void radixSort(int array[], int n)
{
    int m = getMax(array, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        countSortForRadix(array, n, exp);
    }
}

void merge(int *array, int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}

// сортировка слиянием
void mergeSort(int array[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int partitionHoare(int array[], int low, int high)
{
    int pivot = array[low];
    int i = low - 1, j = high + 1;

    while (true)
    {
        do
        {
            i++;
        } while (array[i] < pivot);
        do
        {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        std::swap(array[i], array[j]);
    }
}

// быстрая сортировка (разбиение Хоара)
void quickSortHoare(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot = partitionHoare(array, low, high);
        quickSortHoare(array, low, pivot);
        quickSortHoare(array, pivot + 1, high);
    }
}

int partitionLomuto(int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            std::swap(array[i], array[j]);
        }
    }
    std::swap(array[i + 1], array[high]);
    return (i + 1);
}

// быстрая сортировка (разбиение Ломуто)
void quickSortLomuto(int array[], int low, int high)
{
    if (low < high)
    {
        int pivot = partitionLomuto(array, low, high);
        quickSortLomuto(array, low, pivot - 1);
        quickSortLomuto(array, pivot + 1, high);
    }
}

// пирамидальная сортировка
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Основная функция, выполняющая пирамидальную сортировку
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}