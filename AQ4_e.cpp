#include <iostream>
using namespace std;
#include <cctype> 

int main() {
    char uppercaseChar;
    cout << "Enter an uppercase character: ";
    cin >> uppercaseChar;
    char lowercaseChar = tolower(uppercaseChar);

    std::cout << "The lowercase version is: " << lowercaseChar << std::endl;

    return 0;
}