#include <iostream>
using namespace std;

void combSort(int arr[], int n, int &comparisons, int &swaps){
    int gap = n;
    bool swapped = true;
    const double shrink = 1.3;
    comparisons = 0;
    swaps = 0;

    while (gap > 1 || swapped){
        gap = (int)(gap / shrink);
        if (gap < 1) gap = 1;
        swapped = false;
        for (int i = 0; i + gap < n; i++){
            comparisons++;
            if (arr[i] > arr[i + gap]){
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swaps++;
                swapped = true;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int comparisons = 0, swaps = 0;
    combSort(arr, n, comparisons, swaps);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Total comparisons: " << comparisons << endl;
    cout << "Total swaps: " << swaps << endl;

    delete[] arr;
}