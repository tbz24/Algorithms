#include <iostream>
using namespace std;
 
// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int left, int mid, int right){
    int noL = mid - left + 1;
    int noR = right - mid;
 
    // Create temp arrays
    int arrL[noL], arrR[noR];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < noL; i++)
        arrL[i] = array[left + i];
    for (int j = 0; j < noR; j++)
        arrR[j] = array[mid + 1 + j];
 
    int idL = 0, idR = 0, idM = left;
 
    // Merge the temp arrays back into array[left..right]
    while (idL < noL && idR < noR) {
        if (arrL[idL] <= arrR[idR]) {
            array[idM] = arrL[idL];
            idL++;
        }
        else {
            array[idM] = arrR[idR];
            idR++;
        }
        idM++;
    }
    // Copy the remaining elements of left[], if there are any
    while (idL < noL) {
        array[idM] = arrL[idL];
        idL++;
        idM++;
    }
    // Copy the remaining elements of right[], if there are any
    while (idR < noR) {
        array[idM] = arrR[idR];
        idR++;
        idM++;
    }
}

// begin is for left index and end is right index of the sub-array of arr to be sorted
void mergeSort(int array[], int begin, int end){
    if(begin<end){
        int mid = begin + (end - begin) / 2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid + 1, end);
        merge(array, begin, mid, end);
    }
}
 
void printArray(int A[], int size){
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}
 
int main(){
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    auto arr_size = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Given array is \n";
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
}
