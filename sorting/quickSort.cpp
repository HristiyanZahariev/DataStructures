#include <iostream>

int partition (int arr[], int low, int high) {
    int pivot = arr[low];
    int i = (high + 1);
  
    for (int j = high; j >= low + 1; j--) {
        if (arr[j] >= pivot) {
            i--;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i - 1], arr[low]);
    return (i - 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    int lastIndex = n - 1;
  
    quickSort(arr, 0, lastIndex);

    assert(arr[0] == -3 && "The first element isn't equal to -3");
    assert(arr[1] == 0 && "The second element isn't equal to 0");
    assert(arr[2] == 6 && "The third element isn't equal to 6");
    assert(arr[3] == 21 && "The fourth element isn't equal to 21");
    assert(arr[4] == 23 && "The fifth element isn't equal to 23");
    assert(arr[5] == 24 && "The sixth element isn't equal to 24");

    present(arr, n);
} 