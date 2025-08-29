#include <iostream>
using namespace std;

class SymmetricMatrix {
private:
    int sym[10]; 
    int n = 4;   
public:
    SymmetricMatrix() {
        for (int i = 0; i < 10; i++) {
            sym[i] = 3 * (i + 1);
        }
    }
    int get(int i, int j) {
        if (i >= j) return sym[i * (i + 1) / 2 + j]; 
        return sym[j * (j + 1) / 2 + i];             
    }

    void set(int i, int j, int value) {
        if (i >= j) sym[i * (i + 1) / 2 + j] = value;
        else sym[j * (j + 1) / 2 + i] = value;
    }
    void display() {
        cout << "Symmetric Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    SymmetricMatrix matrix;
    matrix.display();
    return 0;
}