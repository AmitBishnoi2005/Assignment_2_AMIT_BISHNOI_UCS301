#include<iostream>
using namespace std;
string linear_search(int arr[],int key,int length){
    int i=0;
    while(i<length){
        if(arr[i]==key){
            return "key succesfully found ";
        }
        i++;
    }
    return "key not found" ;
}
int main(){
    int arr[]={2,4,6,9,13,18,25,55,56};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << linear_search(arr,56,n);
    return 0;
}