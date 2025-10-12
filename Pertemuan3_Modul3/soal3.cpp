#include <iostream>
using namespace std;

const int SIZE = 3;

void tampilkanArray(int arr[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

void tukarPosisi(int arr1[SIZE][SIZE], int arr2[SIZE][SIZE], int i, int j) {
    int temp = arr1[i][j];
    arr1[i][j] = arr2[i][j];
    arr2[i][j] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[SIZE][SIZE] = {{1,2,3},{4,5,6},{7,8,9}};
    int B[SIZE][SIZE] = {{9,8,7},{6,5,4},{3,2,1}};

    cout << "Array A:" << endl;
    tampilkanArray(A);
    cout << "\nArray B:" << endl;
    tampilkanArray(B);

    tukarPosisi(A, B, 0, 1);

    cout << "\nSetelah menukar elemen [0][1]:" << endl;
    cout << "Array A:" << endl;
    tampilkanArray(A);
    cout << "\nArray B:" << endl;
    tampilkanArray(B);

    int x = 10, y = 20;
    int *px = &x, *py = &y;
    cout << "\nSebelum tukar pointer: x=" << x << ", y=" << y << endl;
    tukarPointer(px, py);
    cout << "Setelah tukar pointer : x=" << x << ", y=" << y << endl;

    return 0;
}
