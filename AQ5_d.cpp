#include <iostream>
using namespace std;

class UpperTriangular {
private:
    int upper[10]; 
    int dim = 4;   

public:
    UpperTriangular() {
        for (int i = 0; i < 10; i++) {
            upper[i] = 2 * (i + 1);
        }
    }
    int get(int i, int j) {
        if (j >= i) return upper[j * (j + 1) / 2 + i]; 
        return 0;                                      
    }

    void set(int i, int j, int value) {
        if (j >= i) upper[j * (j + 1) / 2 + i] = value;
    }
    void display() {
        cout << "Upper Triangular Matrix:\n";
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    UpperTriangular matrix;
    matrix.display();
    return 0;
}