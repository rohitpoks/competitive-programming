#include <iostream>
#include <stdio.h>

using namespace std;
int row;
int col;

int getIndex(int x, int y) {
    return x * col + y;
}

int main() {
    row = 5;
    col = 5;

    float *ptr2 = new float(223.324);

    int *matrix = (int *)malloc(sizeof(int) * row * col);
    if (matrix == NULL) {
        cout << "sorry, not enough memory\n";
        exit(1);
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int index = getIndex(i, j);
            matrix[index] = index;
        } 
    }

    free(matrix);
    delete ptr2;
}
