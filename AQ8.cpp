#include <iostream>
using namespace std;
int main() {
    int arr[] = {1, 2, 3, 6, 3, 1, 5, 7, 22, 13, 456, 32, 45, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int distinct_count = 0;

    for (int i = 0; i < n; i++) {        
        bool is_duplicate = false;

        for (int j = 0; j < i; j++) {            
            if (arr[i] == arr[j]) {
                is_duplicate = true;
                break; 
            }
        }
        if (!is_duplicate) {
            distinct_count++; 
        }
    }

    cout << "Total no of distinct elements: " << distinct_count << endl;

    return 0;
}