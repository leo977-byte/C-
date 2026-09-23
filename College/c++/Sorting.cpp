#include <bits/stdc++.h>
using namespace std;
#define leona ios_base::sync_with_stdio(false); cin.tie(nullptr);
void bubbleSort(int arr[] , int n){//O(n^2) in worst case and O(n) in best case when the array is already sorted
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void selectionSort(int  arr[] , int n){//o(n^2) in all cases
    for(int i = 0; i < n - 1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}
void insertionSort(int arr[] , int n){//O(n^2) in worst case and O(n) in best case when the array is already sorted
    for(int i = 1; i < n; i++){
        int temp = arr[i];
        int j = i - 1;
        while( j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[ j + 1] = temp;
    }
} 
void merge(vector<int> arr, int left, int mid, int right) {//left and right are indecies to help recognizing the sizes of the left side and the right side
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);//store them

    for (int i = 0; i < n1; i++) L[i] = arr[left + i]; //to fill the left subarray and we start from the left index and add i to it to get the next element in the left subarray
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j]; //to fill the right subarray  and we start from the mid + 1 index and add j to it to get the next element in the right subarray

    int l = 0, r = 0, k = left;//helpers for merging the two subarrays and k for the main array
    while (l < n1 && r < n2) {//to merge the two subarrays
        if (L[l] <= R[r]) {
            arr[k] = L[l];
            l++;
        } else {
            arr[k] = R[r];
            r++;
        }
        k++;
    }

    while (l < n1) {//if any remaining elements "left" 
        arr[k] = L[l];
        l++;
        k++;
    }
    while (r < n2) {//remaining elements "right"
        arr[k] = R[r];
        r++;
        k++;
    }
}

void mergeSort(vector<int> arr, int left, int right) {//recursion
    int length = right - left + 1;
    if (length <= 1) return; // Base case when the array has one

    int mid = length / 2;
    mergeSort(arr, left, mid);//recursively sort the left half
    mergeSort(arr, mid + 1, right);//recursively sort the right half
    merge(arr, left, mid, right);//merge the sorted halves 
}

int PartitionFromTheStart(int arr[], int start, int end) {
    int pivot = arr[start];
    int i = start;
    for(int j = start + 1; j <= end; j++){
        if(arr[j] < pivot ){
            i++;
            std::swap(arr[i], arr[j]);//or swap(arr[i], arr[j]);
        }
    }
    i++;//new pivot index
    std::swap(arr[start], arr[i]);//to put the pivot in the right new place
    return i;
}

void quicksort(int arr[], int start , int end){//O(n log n) as best case and O(n^2) as worst case
    if(end <= start) return;//base case
    int pivot = PartitionFromTheStart(arr, start, end);//to get the pivot index 
    quicksort(arr , start, pivot - 1);//to sort the left subarray
    quicksort(arr , pivot + 1, end);//to sort the right subarray
}

int PartitionFromTheEnd(vector<int> arr, int start, int end) {
    int pivot = arr[end];
    int i = start - 1;
    for(int j = start; j <= end - 1; j++){
        if(arr[j] < pivot ){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    i++;//new pivot index
    std::swap(arr[i], arr[end]);//to put the pivot in the right new place
    return i;
}
int QuickSelectHelper(vector<int> arr, int l , int r , int k){
    if(l == r) return arr[l];//base case when the array has one element
    int pivotIndex = PartitionFromTheEnd(arr, l, r);//to get the pivot index
    if(k == pivotIndex) return arr[k];//if the pivot index is the same as k then we found the k-th smallest element
    else if(k < pivotIndex) return QuickSelectHelper(arr, l, pivotIndex - 1, k);//if k is less than the pivot index then we need to search in the left subarray
    else return QuickSelectHelper(arr, pivotIndex + 1, r, k);//if k is greater than the pivot index then we need to search in the right subarray
}



void shellSort(int arr[], int n) {//O(N^3/2) as worst case and O(N log N) as best case
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int current = arr[i];
            int j;

            while( j >= gap && arr[j - gap] > current) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = current;
        }
    }
}
void countingSort(vector<int> arr ){
    int n = arr.size();
    int k = *max_element(arr.begin(), arr.end());
    vector<int> count(k + 1, 0);
    for (int i = 0; i < n; i++) count[arr[i]]++; //frequency array filling
    for (int i = 1; i <= k; ++i) count[i] += count[i - 1];
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--){
        ans[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    arr = ans;
}
void RadixSort(vector<int> arr) {
    int maxNum = *max_element(arr.begin(), arr.end());
    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        countingSort(arr);
    }
}
int main() {
    leona
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Sorted array using Bubble Sort: ";
    bubbleSort(arr, n);
    cout << endl;
    cout << "Sorted array using Selection Sort: ";
    selectionSort(arr, n);
    cout << endl;
    cout << "Sorted array using Insertion Sort: ";
    insertionSort(arr, n);
    cout << endl;
    return 0;
}