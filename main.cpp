#include <iostream>

// сортировка выбором
void selectionSort(int *array, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            std::swap(array[i], array[min_index]);
        }
    }
}

// сортировка пузырьком
void bubbleSort(int *array, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

// сортировка пузырьком с условием Айверсона 1
void bubbleSortWithIverson(int *array, int size) {

}

// сортировка пузырьком с условием Айверсона 1+2
void secondBubbleSortWithIverson(int *array, int size) {

}

// сортировка простыми вставками
void insertionSort(int *array, int size) {
    int temp, key, count = 0;
    bool on_right_place;
    for (int i = 0; i < size - 1; ++i) {
        key = i + 1;
        temp = array[key];
        on_right_place = true;
        for (int j = i + 1; j > 0; --j) {
            if (temp < array[j - 1]) {
                array[j] = array[j - 1];
                key = j - 1;
                on_right_place = false;
            }
        }
        array[key] = temp;
        if (on_right_place) {
            ++count;
        }
    }
}

// сортировка бинарными вставками
void binaryInsertionSort(int *array, int size) {
    int len, key, right, left, mid;
    for (int i = 0; i < size; ++i) {
        key = array[i];
        len = i - 1;
        left = 0;
        right = i - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (array[mid] > array[i]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        while (left <= len) {
            std::swap(array[len], array[len + 1]);
            --len;
        }
        array[len + 1] = key;
    }
}

// сортировка подсчетом (устойчивая)
void countingSort(int *array, int size) {

}

// цифровая сортировка
int getMax(const int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

void countSort(int array[], int n, int exp) {
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[(array[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        array[i] = output[i];
}

void radixSort(int array[], int n) {
    int m = getMax(array, n);
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(array, n, exp);
    }
}


// сортировка слиянием
void merge(int *array, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

// сортировка слиянием
void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; //Same as (left+right)/2, but avoids overflow for large left and h
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

// быстрая сортировка (разбиение Хоара)
void quickSortHoare(int *array, int left, int right) {
    int i = left, j = right;
    int pivot = array[(left + right) / 2];

    /* partition */
    while (i <= j) {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j) {
            std::swap(array[i], array[j]);
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quickSortHoare(array, left, j);
    if (i < right)
        quickSortHoare(array, i, right);
}

// быстрая сортировка (разбиение Ломуто)
int partition(int array[], int low, int high) {
    int i = low;
    for (int j = low; j < high + 1; ++j) {
        if (array[j] <= array[high]) {
            std::swap(array[j], array[i]);
            i += 1;
        }
    }
    return i - 1;
}

void quickSortLomuto(int array[], int low, int high) {
    if (low < high) {
        int pivot = partition(array, low, high);
        quickSortLomuto(array, low, pivot - 1);
        quickSortLomuto(array, pivot + 1, high);
    }
}

// пирамидальная сортировка
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Основная функция, выполняющая пирамидальную сортировку
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int *array;
    int n;
    std::cin >> n;
    array = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    quickSortLomuto(array, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        std::cout << array[i] << " ";
    }
    delete[] array;
    return 0;
}

