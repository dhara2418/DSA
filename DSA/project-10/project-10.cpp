#include <iostream>
using namespace std;

void printArray(int numbers[], int count) {
    cout << "Array: " ;
    for (int i = 0; i < count; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

void selectionSort(int numbers[], int count) {
    for (int i = 0; i < count - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < count; j++) {
            if (numbers[j] < numbers[minPos]) {
                minPos = j;
            }
        }
        int temp = numbers[i];
        numbers[i] = numbers[minPos];
        numbers[minPos] = temp;
    }
    cout << "Selection Sort done!" << endl;
}

void bubbleSort(int numbers[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    cout << "Bubble Sort done!" << endl;
}

void linearSearch(int numbers[], int count, int target) {
    for (int i = 0; i < count; i++) {
        if (numbers[i] == target) {
            cout << "Found at position " << i + 1 << endl;
            return;
        }
    }
    cout << "Not found." << endl;
}

void binarySearch(int numbers[], int count, int target) {
    int start = 0;
    int end = count - 1;

    while (start <= end) {
        int middle = (start + end) / 2;

        if (numbers[middle] == target) {
            cout << "Found at position " << middle + 1 << endl;
            return;
        }
        else if (numbers[middle] < target) {
            start = middle + 1;
        }
        else {
            end = middle - 1;
        }
    }
    cout << "Not found." << endl;
}

int main() {
    int total;
    cout << "Enter number of elements for Array: ";
    cin >> total;

    int numbers[100];
    cout << "Enter " << total << " numbers:" << endl;
    for (int i = 0; i < total; i++) {
        cout << i << " index: ";
        cin >> numbers[i];
    }

    int choice;
    do {
        cout << endl << "MENU:" << endl;
        cout << "1. Selection Sort" << endl;
        cout << "2. Bubble Sort" << endl;
        cout << "3. Linear Search" << endl;
        cout << "4. Binary Search" << endl;
        cout << "5. Print Array" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            selectionSort(numbers, total);
        }
        else if (choice == 2) {
            bubbleSort(numbers, total);
        }
        else if (choice == 3) {
            int searchNum;
            cout << "Enter number to search: ";
            cin >> searchNum;
            linearSearch(numbers, total, searchNum);
        }
        else if (choice == 4) {
            int searchNum;
            cout << "Enter number to search: ";
            cin >> searchNum;
            binarySearch(numbers, total, searchNum);
        }
        else if (choice == 5) {
            printArray(numbers, total);
        }
        else if (choice == 0) {
            cout << "You chose to exit!" << endl;
        }
        else {
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}
