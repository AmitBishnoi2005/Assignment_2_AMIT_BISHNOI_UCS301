#include<iostream>
using namespace std;
struct Array{
    int A[10];
    int size;
    int length;
};
string bSearch(struct Array arr1,int key){
    int i,j,mid;
    i=0;
    j=arr1.length-1;
    while(i<=j){
        mid = (i+j)/2;
        if(key<arr1.A[mid]){
            j=mid-1;
        }
        else if(key>arr1.A[mid]){
            i=mid+1;
        }
        else{
            return "key found succesfully";
        }
    }
    return "key not found";
}
int main(){
    struct Array arr1={{1,2,4,7,9,14,17,23},10,8};
    cout << bSearch(arr1,9);
    return 0;
}