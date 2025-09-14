#include "iostream"
using namespace std;

void linearSearch(int arr[], int n, int target){
    bool found = false;

    for (int i=0; i<n; i++){
        if (arr[i] == target){
            cout << "Element found at index " << i << endl;
            found=true;
        }
    }
    if (!found){
        cout << "Element not found in the array." << endl;
    }
}

int main(){
    int n, target;
    cout << "Enter the size of the array: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter " << n << " elements of the array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the target value to search: ";
    cin >> target;
    linearSearch(arr, n, target);

    delete[] arr;
}
