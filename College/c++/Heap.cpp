#include<bits/stdc++.h>
#define leona ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int inf = 1e7;
using namespace std;
void heapify(int arr[], int n, int i) {//the n is the size of the heap and i is the index of the current node we want to heapify
    int max = i; // Initialize largest as root
    int left = 2 * i + 1; // left child index
    int right = 2 * i + 2; // right child index

    // If left child is larger than root 
    if (left < n && arr[left] > arr[max])
        max = left;//update max to the left child index

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[max])
        max = right;//update max to the right child index

    // If largest is not the root meaning the current node is smaller than at least one of its children
    if (max != i) {
        swap(arr[i], arr[max]); // Swap root with largest
        heapify(arr, n, max);
    }
}
void buildHeap(int arr[], int n) {
    // Perform reverse level order traversal from last non-leaf node and heapify each node
    for (int i = (n / 2) - 1; i >= 0; i--) {//start from the last non-leaf node and go up to the root
        heapify(arr, n, i);
    }
}
void heapSort(int arr[], int n) {//o(nlogn) time complexity and o(1) space complexity
    buildHeap(arr, n); // Build heap (rearrange array)

    // One by one extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Move current root to end to make it sorted in ascending order
        heapify(arr, i, 0); // call max heapify on the reduced heap
    }
}
int main() {
    leona
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}