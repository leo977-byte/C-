#include <bits/stdc++.h>
using namespace std;
#define leon ios_base::sync_with_stdio(false); cin.tie(nullptr);
int binarySearch(int arr[], int l, int r, int x) {//recursively O(log n) as we are halving the search space in each step
    if (r >= l) {//base case: if the search space is valid
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
int linearSearch(int arr[], int n, int x) {//O(n) as we are checking each element in the array
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i;
    }
    return -1;
}
int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result != -1) {
        cout << "Element is present at index " << result << endl;
    } else {
        cout << "Element is not present in array" << endl;
    }
    return 0;
}
