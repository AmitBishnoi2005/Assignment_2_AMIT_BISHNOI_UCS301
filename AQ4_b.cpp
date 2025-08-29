#include<iostream>
using namespace std;

int main(){
    string s = "hello";
    string rev_s ;
    int len_s = s.length();
    rev_s.resize(len_s);
    for(int i=0,j=len_s-1;i<len_s;i++,j--){
        rev_s[i]=s[j];
    }
    cout << "reversed string: ";
    for(int i=0;i<rev_s.length();i++){
        cout << rev_s[i] ;
    }
    return 0;
}