#include <iostream>
using namespace std;

void sortArray(int numbers[], int size) {
    for (int pass = 0; pass < size - 1; pass++) {
        for (int i=0; i< size-pass-1; i++) {
            if (numbers[i] > numbers[i + 1]) {
                int temp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i+1] = temp;
            }
        }
    }
}

int main() {
    int data[] = {66, 33,22, 11,55, 77, 99};
    int length = sizeof(data) / sizeof(data[0]);
    sortArray(data, length);
    cout << "sorted array: ";
    for (int i = 0; i < length; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    
    return 0;
}