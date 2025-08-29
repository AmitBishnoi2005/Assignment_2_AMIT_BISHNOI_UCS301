#include <iostream>
using namespace std;

int countInversions(int a[], int n) {
    int c = 0;
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(a[i]>a[j]) c++;
    return c;
}

int main() {
    int a[5] = {5, 2, 4, 1, 3};
    int n = 5;
    cout<<"Array: ";
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<"\nInversions: "<<countInversions(a, n);
    return 0;
}