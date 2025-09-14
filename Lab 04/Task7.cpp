#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void bubbleSort(int arr[], int n, int &comparisons, int &swaps){
    comparisons = swaps = 0;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            comparisons++;
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
}

void insertionSort(int arr[], int n, int &comparisons, int &swaps){
    comparisons = swaps = 0;
    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0){
            comparisons++;
            if (arr[j] > key){
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            } else{
                break;
            }
        }
        arr[j + 1] = key;
    }
}

void shellSort(int arr[], int n, int &comparisons, int &swaps){
    comparisons = swaps = 0;
    for (int gap = n / 2; gap > 0; gap /= 2){
        for (int i = gap; i < n; i++){
            int temp = arr[i];
            int j = i;
            while (j >= gap){
                comparisons++;
                if (arr[j - gap] > temp){
                    arr[j] = arr[j - gap];
                    swaps++;
                    j -= gap;
                } else {
                    break;
                }
            }
            arr[j] = temp;
        }
    }
}
void copyArray(int src[], int dest[], int n){
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

int main(){
    int n = 1000;
    int* arr = new int[n];
    int* arrCopy = new int[n];

    srand(time(0));
    for (int i = 0; i < n; i++){
        arr[i] = rand() % 10000;
    }
    int comparisons, swaps;
    clock_t start, end;

    copyArray(arr, arrCopy, n);
    start = clock();
    bubbleSort(arrCopy, n, comparisons, swaps);
    end = clock();
    cout << "Bubble Sort:\n";
    cout << "Time: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";
    cout << "Comparisons: " << comparisons << ", Swaps: " << swaps << "\n\n";

    copyArray(arr, arrCopy, n);
    start = clock();
    insertionSort(arrCopy, n, comparisons, swaps);
    end = clock();
    cout << "Insertion Sort:\n";
    cout << "Time: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";
    cout << "Comparisons: " << comparisons << ", Swaps: " << swaps << "\n\n";

    copyArray(arr, arrCopy, n);
    start = clock();
    shellSort(arrCopy, n, comparisons, swaps);
    end = clock();
    cout << "Shell Sort:\n";
    cout << "Time: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";
    cout << "Comparisons: " << comparisons << ", Swaps: " << swaps << "\n\n";

    delete[] arr;
    delete[] arrCopy;
}