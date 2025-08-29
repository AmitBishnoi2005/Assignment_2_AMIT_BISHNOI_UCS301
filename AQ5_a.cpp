#include <iostream>
using namespace std;

class DiagonalMatrix {
private:
    int diagonal[4]; 
    int size = 4;   

public:
    DiagonalMatrix() {
        for (int i = 0; i < size; i++) {
            diagonal[i] = i + 1;
        }
    }
    int get(int i, int j) {
        if (i == j) return diagonal[i]; 
        return 0;                       
    }
    void set(int i, int j, int value) {
        if (i == j) diagonal[i] = value; 
    }
    void display() {
        cout << "Diagonal Matrix:\n";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    DiagonalMatrix matrix;
    matrix.display();
    return 0;
}