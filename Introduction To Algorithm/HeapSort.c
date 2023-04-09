#include <stdio.h>
#include <stdlib.h>

// Definition of binary heap
typedef struct {
    int *data;
    int size;
} BinaryHeap;

// Functions for manipulating binary heap
BinaryHeap* createBinaryHeap(int size);
void insert(BinaryHeap* heap, int value);
int extractMin(BinaryHeap* heap);
void heapify(BinaryHeap* heap, int i);

// Sorting function that uses binary heap
void heapSort(int arr[], int size);

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    heapSort(arr, size);
    
    printf("Sorted array: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}

BinaryHeap* createBinaryHeap(int size) {
    BinaryHeap* heap = malloc(sizeof(BinaryHeap));
    heap->data = malloc(size * sizeof(int));
    heap->size = 0;
    return heap;
}

void insert(BinaryHeap* heap, int value) {
    int i = heap->size;
    heap->data[i] = value;
    heap->size++;
    
    while(i > 0 && heap->data[(i-1)/2] > heap->data[i]) {
        int temp = heap->data[(i-1)/2];
        heap->data[(i-1)/2] = heap->data[i];
        heap->data[i] = temp;
        i = (i-1)/2;
    }
}

int extractMin(BinaryHeap* heap) {
    int min = heap->data[0];
    heap->size--;
    heap->data[0] = heap->data[heap->size];
    heapify(heap, 0);
    return min;
}

void heapify(BinaryHeap* heap, int i) {
    int left = 2*i+1;
    int right = 2*i+2;
    int smallest = i;
    
    if(left < heap->size && heap->data[left] < heap->data[smallest]) {
        smallest = left;
    }
    
    if(right < heap->size && heap->data[right] < heap->data[smallest]) {
        smallest = right;
    }
    
    if(smallest != i) {
        int temp = heap->data[i];
        heap->data[i] = heap->data[smallest];
        heap->data[smallest] = temp;
        heapify(heap, smallest);
    }
}

void heapSort(int arr[], int size) {
    BinaryHeap* heap = createBinaryHeap(size);
    
    for(int i = 0; i < size; i++) {
        insert(heap, arr[i]);
    }
    
    for(int i = 0; i < size; i++) {
        arr[i] = extractMin(heap);
    }
    
    free(heap->data);
    free(heap);
}