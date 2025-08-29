#include <iostream>
using namespace std;

class TriDiagonalMatrix {
private:
    int elements[10]; 
    int size = 4;   

public:
    TriDiagonalMatrix() {
        elements[0] = 1; elements[1] = 2; elements[2] = 3;         
        elements[3] = 5; elements[4] = 6; elements[5] = 7; elements[6] = 8; 
        elements[7] = 2; elements[8] = 3; elements[9] = 4;        
    }
    int get(int i, int j) {
        if (i == j) return elements[i + 3];           
        if (i == j + 1) return elements[j];           
        if (j == i + 1) return elements[i + 7];     
        return 0;                                     
    }
    void set(int i, int j, int value) {
        if (i == j) elements[i + 3] = value;       
        else if (i == j + 1) elements[j] = value; 
        else if (j == i + 1) elements[i + 7] = value; 
    }
    void display() {
        cout << "Tri-diagonal Matrix:\n";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    TriDiagonalMatrix matrix;
    matrix.display();
    return 0;
}