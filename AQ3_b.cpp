#include<iostream>
using namespace std;
int findMissingNumber(int arr[], int size) {
    int l = 0;
    int r = size - 1;
    if (size == 0) return 1;
    if (arr[0] != 1) return 1;
    if (arr[size - 1] != size + 1) return size + 1;
    
    while (l <= r) {
        int mid = l + (r-l) / 2;
                if (arr[mid] != mid + 1) {
            if (mid == 0 || arr[mid - 1] == mid) {
                return mid + 1; 
            }
            r = mid - 1; 
        } else {
            l = mid + 1; 
        }
    }
    
    return -1;
}
int main(){
    int arr[]={1,2,3,4,5,6,7};// n = 8, size = 7, missing 8
    int n = sizeof(arr)/sizeof(arr[0]);
    int missing = findMissingNumber(arr, n);
    cout << "Missing number: " << missing << endl;
    return 0;
}