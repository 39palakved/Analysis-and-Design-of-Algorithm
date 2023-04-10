#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
   for(int i = 0; i < size; i++) {
      if(arr[i] == key) {
         return i;
      }
   }
   return -1; // key not found
}

int main() {
   int arr[] = {12, 45, 6, 23, 67, 99, 54};
   int key = 23;
   int size = sizeof(arr)/sizeof(arr[0]);
   
   int result = linearSearch(arr, size, key);
   if(result == -1) {
      printf("Element not found");
   } else {
      printf("Element found at index %d", result);
   }
   return 0;
}