#include <iostream>
using namespace std;

class LowerTriangular {
private:
    int lower[10]; 
    int n = 4;     

public:
    LowerTriangular() {
        for (int i = 0; i < 10; i++) {
            lower[i] = i + 1;
        }
    }
    int get(int i, int j) {
        if (i >= j) return lower[i * (i + 1) / 2 + j]; 
        return 0;                                      
    }

    void set(int i, int j, int value) {
        if (i >= j) lower[i * (i + 1) / 2 + j] = value;
    }
    void display() {
        cout << "Lower Triangular Matrix:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    LowerTriangular matrix;
    matrix.display();
    return 0;
}