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

void testSortingAlgorithm(const std::function<void(int[], int)> &sortingFunc, const std::string &sortName, int *arrayCopy, int size)
{

    int *tempArray = new int[size];
    std::copy(arrayCopy, arrayCopy + size, tempArray);

    auto start = std::chrono::high_resolution_clock::now();
    sortingFunc(tempArray, size);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    double executionTime = elapsed.count();

    std::cout << std::fixed << std::setprecision(7);
    std::cout << sortName << " Execution Time: " << executionTime << " seconds" << std::endl;

    for (int i = 0; i < size; ++i)
    {
        std::cout << tempArray[i] << " ";
    }
    std::cout << std::endl;

    delete[] tempArray;
}

int main()
{
    int size = 10;
    int *array = generateArray(size);
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    testSortingAlgorithm(selectionSort, "Selection Sort", array, size);
    testSortingAlgorithm(bubbleSort, "Bubble Sort", array, size);
    testSortingAlgorithm(bubbleSortWithIverson, "Bubble Sort with Iverson", array, size);
    testSortingAlgorithm(insertionSort, "Insertion Sort", array, size);
    testSortingAlgorithm(binaryInsertionSort, "Binary Insertion Sort", array, size);
    //testSortingAlgorithm(countSort, "Count Sort", array, size);
    testSortingAlgorithm(radixSort, "Radix Sort", array, size);
    testSortingAlgorithm([](int arr[], int size)
                         { mergeSort(arr, 0, size - 1); },
                         "Merge Sort", array,
                         size);
    testSortingAlgorithm([](int arr[], int size)
                         { quickSortHoare(arr, 0, size - 1); },
                         "Quick Sort Hoare's partition", array,
                         size);
    testSortingAlgorithm([](int arr[], int size)
                         { quickSortLomuto(arr, 0, size - 1); },
                         "Quick Sort Lomuto's partition", array,
                         size);
    testSortingAlgorithm(heapSort, "Heap Sort", array, size);

    delete[] array;
    return 0;
}
