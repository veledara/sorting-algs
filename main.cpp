#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <random>
#include <iomanip>
#include <algorithm>
#include <functional>
#include "sorting_algs.h"

int *generateArray(int size)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100000);
    int *array = new int[size];
    for (int i = 0; i < size; ++i)
    {
        array[i] = dist(gen);
    }
    return array;
}

void testSortingAlgorithm(const std::function<void(int[], int)> &sortingFunc, const std::string &sortName, int size)
{
    int *array = generateArray(size);
    int *arrayCopy = new int[size];
    std::copy(array, array + size, arrayCopy);

    auto start = std::chrono::high_resolution_clock::now();
    sortingFunc(arrayCopy, size);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    double executionTime = elapsed.count();

    std::cout << std::fixed << std::setprecision(7);
    std::cout << sortName << " Execution Time: " << executionTime << " seconds" << std::endl;

    delete[] array;
    delete[] arrayCopy;
}

int main()
{
    int size = 10000;
    testSortingAlgorithm(selectionSort, "Selection Sort", size);
    testSortingAlgorithm(bubbleSort, "Bubble Sort", size);
    testSortingAlgorithm(bubbleSortWithIverson, "Bubble Sort with Iverson", size);
    testSortingAlgorithm(insertionSort, "Insertion Sort", size);
    testSortingAlgorithm(binaryInsertionSort, "Binary Insertion Sort", size);
    testSortingAlgorithm([](int arr[], int size)
                         { countSort(arr, size, 1); },
                         "Count Sort",
                         size);
    testSortingAlgorithm(radixSort, "Radix Sort", size);
    testSortingAlgorithm([](int arr[], int size)
                         { mergeSort(arr, 0, size - 1); },
                         "Merge Sort",
                         size);
    testSortingAlgorithm([](int arr[], int size)
                         { quickSortHoare(arr, 0, size - 1); },
                         "Quick Sort Hoare's partition",
                         size);
    testSortingAlgorithm([](int arr[], int size)
                         { quickSortLomuto(arr, 0, size - 1); },
                         "Quick Sort Lomuto's partition",
                         size);
    testSortingAlgorithm(heapSort, "Heap Sort", size);

    return 0;
}
