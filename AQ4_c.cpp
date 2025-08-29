#include<iostream>
using namespace std;
void delete_s(string &s, int index, int &len_s) {
    if (index >= 0 && index < len_s) {
        for (int i = index; i < len_s - 1; i++) {
            s[i] = s[i + 1];
        }
        s.resize(len_s - 1);
        len_s--; 
    }
}
int main(){
    string s = "hello my name is amit";
    int len_s = s.length();
    for(int i=0;i<len_s;i++){
        if(s[i] == 'a' || s[i] == 'e' ||s[i] == 'i'||s[i] == 'o'||s[i] == 'u' ){
            delete_s(s,i,len_s);
        }
    }
    for(int i=0;i<len_s;i++){
        cout << s[i] ;
    }
    return 0;
}