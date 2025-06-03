#ifndef SORTS_H
#define SORTS_H

#include <stdlib.h>
#include "sort_helper.h"

/*** code for selection sort ****/

// Returns the minimum integer from a range in an array
// Input: array - An array of integers
//        start - Where to start looking in an array
//        stop - End of where to search. Typically the 'size' of the array.
// Output: The index in an array of the minimum value between a range [start,stop]
int findMinimum(int *array, int start, int stop)
{
    if (!array || start > stop) {
        exit(EXIT_FAILURE);
    }
    int minIndex = start;
    for (int i = start + 1; i <= stop; i++) {
        if (array[i] < array[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex; // modify to return the index of the min value
}


// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  -  'print' tells it to print out after each interation
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void selectionSortIntegers(int *array, unsigned int size, int print)
{
    if (!array) {
        exit(EXIT_FAILURE);
    }
    for (unsigned int i = 0; i + 1 < size; i++) {
        unsigned int minIndex = findMinimum(array, i, size - 1);
        if (minIndex != i) {
            swap(&array[i], &array[minIndex]);
        }
        if (print) {
            printIntArray(array, size);
        }
    }
}

/***  Code for Insertion Sort ***/

// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  - 'print' tells it to print out after each iteration 
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void insertionSortIntegers(int *array, unsigned int size, int print)
{
    if (!array) {
        exit(EXIT_FAILURE);
    }
    for(unsigned int i = 1; i < size; i++) {
        int k = array[i];
        int j = (int)i - 1;

        while (j >= 0 && array[j] > k) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = k;

        if (print) {
            printIntArray(array, size);
        }
    }
}

/** Code for Bubble Sort (from Lab -if not compiling, comment out the internals, but leave the function definition) ***/

// =============== Sort Function ===============
// Name: bubblesort
// Desc: O(n^2) comparison sort
// param(1): 'array' is a pointer to an integer address.
//           This is the start of some 'contiguous block of memory'
//           that we will sort.
// param(2)  'size' tells us how big the array of
//           data is we are sorting.
// param(3) 'print' tells it to print out after each iteration.
// Output:   No value is returned, but 'array' should
//           be modified to store a sorted array of size.
void bubbleSortIntegers(int *array, unsigned int size, int print)
{
    if (!array) {
        exit(EXIT_FAILURE);
    }
    int swapped = 1;
    while (swapped) {
        swapped = 0;
    }
        for (unsigned int i = 0; i + 1 < size; i++) {
            if (array[i] > array[i + 1]) {
                swap(&array[i], &array[i + 1]);
                swapped = 1;
            }
        }
    if (print) {
        printIntArray(array, size);
    }
}

// ** You will work on merge sort during the lab on Module 06 ** //

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int temp[], int l, int m, int r)
{
    if (arr == NULL || temp == NULL)
    {
        exit(1);
    }
    if (l > m || m + 1 > r)
        return;
    int i = l;
    int j = m + 1;
    int start = l;
    while(i <= m && j <= r) {
        if(arr[i] <= arr[j]) {
            temp[start] = arr[i];
            i++;
        } else {
            temp[start] = arr[j];
            j++;
        }
        start++;
    }
    while(i <= m) {
        temp[start++] = arr[i++];
    }
    while(j <= r) {
        temp[start++] = arr[j++];
    }
    for (int k = l; k <= r; k++) {
        arr[k] = temp[k];
    }
}

// To be built during week 6 lab
// Name: mergeSort
// Input(s):
//          (1) 'arr' is a pointer to an integer address.
//              This is the start of some 'contiguous block of memory' that we will sort.
//          (2) 'temp' is a pointer to an integer address.
//          	This helps temporarily store the sorted subarray.
//          (3) 'l' and 'r' are integers, which are the first index and the last index of 'arr' respectively.
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void merge_sort(int arr[], int temp[], int l, int r)
{
    if (l < r) { // if left is less than right
        int m = l + ((r-l)/2); // split the list in half
        merge_sort(arr, temp, l, m); // sort the left side
        merge_sort(arr, temp, m+1, r); // sort the right side
        merge(arr, temp, l, m, r); // merge both sides
    }
}

// lab build, merge sort

void mergeSortIntegers(int *array, unsigned int size, int print)
{ // print is ignored for this one
    if (array == NULL)
    {
        exit(1);
    }
    if (size <= 1)
        return;

    int *temp = (int *)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++) {
        temp[i] = array[i];
    }
    merge_sort(array, temp, 0, size - 1);
    free(temp);
}

// provided code 

// =============== Helper Functions ===============
// Name:    compare
// Desc:    A compare function which returns
//          a value (positive,negative, or 0)
//          to show if the result is >,<, or =.
//
// Input:   a and b here are generic types,
//          that is why they are 'void'
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void quickSortIntegers(int* array, unsigned int size, int print) 
{   // print is ignored as qsort doesn't use it
    qsort(array, size, sizeof(int), compare);
}

#endif