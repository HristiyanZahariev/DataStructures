#include <iostream>
#include <assert.h>

void max_heapify(int arr[], size_t n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = left + 1;

    // used the algorithm to determine the left and right child of a node: https://medium.com/basecs/learning-to-love-heaps-cef2b273a238

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        max_heapify(arr, n, largest);
    }
}

void build_max_heap(int a[], size_t n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(a, n, i);
}

void heapSort(int arr[], size_t n) {
    build_max_heap(arr, n);

    for (int i=n-1; i>=0; i--) {
        std::swap(arr[0], arr[i]);
        max_heapify(arr, i, 0);
    }
}

void present(int arr[], size_t n) {
    std::cout << std::endl << "Sorted Data ";
    for (int i = 0; i < n; i++)
        std::cout << "->" << arr[i];
    std::cout << std::endl;
}

int main() { 
    int arr[] = {23, 24, 6, 21, 0, -3};
    int n = sizeof(arr)/sizeof(arr[0]);
  
    heapSort(arr, n);

    assert(arr[0] == -3 && "The first element isn't equal to -3");
    assert(arr[1] == 0 && "The second element isn't equal to 0");
    assert(arr[2] == 6 && "The third element isn't equal to 6");
    assert(arr[3] == 21 && "The fourth element isn't equal to 21");
    assert(arr[4] == 23 && "The fifth element isn't equal to 23");
    assert(arr[5] == 24 && "The sixth element isn't equal to 24");

    present(arr, n);
} 