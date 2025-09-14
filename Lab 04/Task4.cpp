#include "iostream"
using namespace std;

void insertionSort(int arr[], int n){
    for (int i=1; i <n; i++){
        int key=arr[i];
        int j=i-1;

        while (j>= 0 && arr[j] >key){
            arr[j+1]= arr[j];
            j--;
        }
        arr[j +1]=key;
    }
}

int binarySearch(int arr[], int n, int target){
    int left=0, right=n-1;
    while (left <=right){
        int mid =(left +right)/2;
        if (arr[mid]==target) {
            return mid;
        } 
        else if (arr[mid] <target){
            left =mid+1;
        } 
        else {
            right =mid-1;
        }
    }
    return -1;
}

int main(){
    int n, target;

    cout << "Enter the number of elements: ";
    cin >> n;
    int* arr = new int[n]; // dynamic array

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    insertionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Enter the target value to search: ";
    cin >> target;
    int result = binarySearch(arr, n, target);

    if (result != -1){
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    delete[] arr;
}