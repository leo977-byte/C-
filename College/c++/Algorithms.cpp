#include <bits/stdc++.h>
using namespace std;
const int N= 1e6+5,MOD=1e9+7,INF=1e18+5;
#define leon ios_base::sync_with_stdio(false); cin.tie(nullptr);

void insertion(int array[]){
    for (int i = 1; i <= 9; i++){//O(N^2) as worst case and O(N) as best case
        int temp = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > temp){//if greater than temp then we need to shift the value to the right
            array[j + 1] = array[j];// to shift the value to the right
            j--;//to check the next value in the left side
        }
        array[ j + 1 ]= temp;// to put the value in the right place when the while loop finishes 
    }
}
//---------------------------------------------------------------------------------------------
void Selection(int array[]){// O(N^2) as worst case and O(N^2) as best case
    for(int i = 0; i < 8; i++){//i remains the same 
        int min = i;// to store the index of the minimum value
        for (int j = i + 1; j < 9; j++){
            if(array[j]< array[min]){//if smaller then add to the minimum value
                array[min] = array[j];// to update the minimum value
            }
        }
        swap(array[i], array[min]);// to swap the values

    }
}
//---------------------------------------------------------------------------------------------
void bubble(int array[]){//O(N^2) as worst case and O(N) as best case
    for(int i = 0; i  < 8; i++){
        for(int j = 0; j < 9 - i - 1; j++){
            if(array[j] > array[j+ 1]){
                swap(array[j], array[j + 1]);
            }
        }
    }
}
//---------------------------------------------------------------------------------------------
void shellSort(int arr[], int n) {//O(N^3/2) as worst case and O(N log N) as best case
    for (int gap = n / 2; gap > 0; gap /= 2) {// gap is the middle point in the array
        for (int i = gap; i < n; i++) {//i is the index of the current element which is > gap
            int temp = arr[i];// we will hold one
            int j;//we will need it outside the inner loop so declare it outside
            for (j = i; j >= 0 && arr[j - gap] > temp; j -= gap) {//j 
                arr[j] = arr[j - gap];//to swap the values if the value at j-gap is greater than temp
            }
            arr[j] = temp;//to put the value back in the right place after the inner loop finishes
        }
    }
}
//---------------------------------------------------------------------------------------------

void merge(vector<int>& arr, int left, int mid, int right) {//maybe dynamic array -> int*L = new int[n1], *R = new int[n2];
    int n1 = mid - left + 1;//size of the left subarray because i take the mid with the left array
    int n2 = right - mid;//size of the right subarray
    vector<int> L(n1), R(n2);//store them

    for (int i = 0; i < n1; i++) L[i] = arr[left + i]; //to fill the left subarray and we start from the left index and add i to it to get the next element in the left subarray
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j]; //to fill the right subarray  and we start from the mid + 1 index and add j to it to get the next element in the right subarray

    int i = 0, j = 0, k = left;//helpers for merging the two subarrays and k for the main array
    while (i < n1 && j < n2) {//to merge the two subarrays
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {//if any remaining elements "left" 
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {//remaining elements "right"
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {//recursion
    if (left >= right) return; // Base case when the array has one or zero elements

    int mid = left + (right - left) / 2;//find the mid
    mergeSort(arr, left, mid);//recursively sort the left half
    mergeSort(arr, mid + 1, right);//recursively sort the right half
    merge(arr, left, mid, right);//merge the sorted halves 
}

//---------------------------------------------------------------------------------------------
int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int i = start -1;
    for(int j = start; j <= end - 1; j++){
        if(arr[j] < pivot ){
            i++;
            swap(arr[i], arr[j]);//or swap(arr[i], arr[j]);
        }
    }
    i++;//new pivot index
    swap(arr[i], arr[end]);//to put the pivot in the right new place
    return i;//new pivot index
}
void quicksort(int arr[], int start , int end){//O(n log n) as best case and O(n^2) as worst case
    if(end <= start) return;//base case
    int pivot = partition(arr, start, end);//to get the pivot index 
    quicksort(arr , start, pivot - 1);//to sort the left subarray
    quicksort(arr , pivot + 1, end);//to sort the right subarray
}
//---------------------------------------------------------------------------------------------.
void count_sort(int arr[], int n)
{
    int k = *max_element(arr, arr + n);

    int count[k + 1] = {0};
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    for (int i = 1; i <= k; i++) {
        count[i] = count[i] + count[i - 1];//prefix sum to get the position of each element in the output array
    }
    int ans[n];
    for (int i = n - 1; i >= 0; i--) {
        int value = arr[i];          
        count[value] = count[value] - 1; 
        int position = count[value]; 
        ans[position] = value;        
    }
    for (int i = 0; i < n; i++) {
        arr[i] = ans[i];
    }
}
//---------------------------------------------------------------------------------------------

int getMax(int arr[], int n)
{//max to know the # of iterations
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp)
{//based on units andd tens and so on

    int output[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
//---------------------------------------------------------------------------------------------

int main(){
   int arr[] = {1, 8, 3, 6, 2, 7, 5, 4, 9};
    quicksort(arr, 0, 8);//CHANGE THE SORTING ALGORITHM HERE
    for (int i = 0; i < 9; i++) {
        cout << arr[i] << " ";
    }
}

//only merge and counting sort use vector because we need to create temporary arrays for the left and right subarrays, 
//and using vectors allows us to easily manage the dynamic memory allocation and deallocation. 
//In contrast, the other sorting algorithms (insertion, selection, bubble, shell sort, and quicksort)
// can be implemented using simple arrays without the need for additional temporary storage, 
//making them more straightforward in terms of memory management.