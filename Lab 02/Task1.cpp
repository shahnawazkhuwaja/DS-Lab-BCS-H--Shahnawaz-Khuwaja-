#include "iostream"
using namespace std;

int main(){
    int size;
    cout << "Enter the size of array: " << endl;
    cin >> size;

    int* arr = new int[size];

    for(int i = 0; i < size; i++){
        arr[i] = 0;
    }
    cout << "Array initialised with zero:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    int position, value;
    char choice;

    while (true)
    {
        cout << "Enter position: ";
        cin >> position;

        if (position < 0 || position >= size)
        {
            cout << "Invalid Positon" << endl;
        }
        else{
            cout << "Enter Value: ";
            cin >> value;
            arr[position] = value;
        }

        cout << "Do you want to update more values: (y/n)";
        cin >> choice;
        if(choice != 'y' && choice != 'Y'){
            break;
        }
    }
    cout << "Array: " << endl;
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    delete[] arr;
}
