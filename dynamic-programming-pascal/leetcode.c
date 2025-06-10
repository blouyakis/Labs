#include <stdio.h>
#include <stdlib.h>

// LeetCode 1043. Partition Array for Maximum Sum

int max(int a, int b) { // function finds max of 2 integers
    return a > b ? a : b; // returns a if a > b, returns b if b > a
}

// Given an integer array arr, partition the array into (contiguous) subarrays of length 
// at most k. After partitioning, each subarray has their values changed to become the 
// maximum value of that subarray. Return the largest sum of the given array after partitioning.
int maxSumAfterPartitioning(int* arr, int arrSize, int k) {
    int* dp = (int*)calloc(arrSize + 1, sizeof(int)); // create space in memory for the array
    for (int i = 1; i <= arrSize; i++) { // iterate over the array
        int newMax = 0; // variable to store the new maximum integer
        for (int j = 1; j <= k && j <= i; j++) { // iterate over all partitions 
            newMax = max(newMax, arr[i - j]); // update the new max value
            dp[i] = max(dp[i], dp[i - j] + newMax * j); // update the new array
        }
    }
    int result = dp[arrSize];
    free(dp); // free memory space
    return result;
}
