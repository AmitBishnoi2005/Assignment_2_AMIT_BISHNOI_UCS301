#include<iostream>
using namespace std;

int main(){
    string word = "programming";

    int n = word.length();
    cout << "Original string: " ;
    cout << word << endl;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (word[j] > word[j + 1]) {
                char temp = word[j];
                word[j] = word[j + 1];
                word[j + 1] = temp;
            }
        }
    }
    cout << "alphabetical ordered string: "<< word;
    return 0;
}