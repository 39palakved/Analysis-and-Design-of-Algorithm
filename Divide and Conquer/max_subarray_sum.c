#include <stdio.h>
#include <limits.h>

// Function to find maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find maximum of three integers
int max3(int a, int b, int c) {
    return max(max(a, b), c);
}

// Function to find the maximum subarray sum of an array using the Divide and Conquer algorithm
int maxSubarraySum(int arr[], int low, int high) {
    // Base case: only one element in the array
    if (low == high) {
        return arr[low];
    }

    // Divide the array into two halves
    int mid = (low + high) / 2;
    
    // Find the maximum subarray sum in the left half
    int leftMax = maxSubarraySum(arr, low, mid);
    
    // Find the maximum subarray sum in the right half
    int rightMax = maxSubarraySum(arr, mid + 1, high);
    
    // Find the maximum subarray sum that crosses the middle point
    int leftSum = INT_MIN;
    int rightSum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }
    int crossMax = leftSum + rightSum;

    // Return the maximum of the three sums
    return max3(leftMax, rightMax, crossMax);
}

// Driver program to test above functions
int main() {
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, 0, n - 1);
    printf("Maximum subarray sum is %d\n", maxSum);
    return 0;
}