#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

void heapify(int arr[], int n, int i){ 
    int parent = (i - 1) / 2; 
    if (arr[parent] > 0){ 
        if (arr[i] > arr[parent]){ 
            int temp = arr[i];
            arr[i] = arr[parent];
            arr[parent] = temp; 
            heapify(arr, n, parent); 
        } 
    } 
} 
void insertNode(int arr[], int n, int Key){ 
    n = n + 1; 
    arr[n - 1] = Key; 
    heapify(arr, n, n - 1); 
} 
void printArray(int arr[], int n){ 
    for (int i = 0; i < n; ++i) 
        printf("%d ",arr[i]);
    printf("\n"); 
} 
int main(){ 
    int arr[MAX] = { 10, 5, 3, 2, 4 }; 
    int n = sizeof(arr) / sizeof(arr[0]);  
    int key = 15;  
    insertNode(arr, n, key);  
    printArray(arr, n); 
    return 0; 
}