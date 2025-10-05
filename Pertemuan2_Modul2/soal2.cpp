#include <iostream>
using namespace std;

void tukarPointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

void tukarReference(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int x = 1, y = 2, z = 3;

    cout << "Sebelum tukar: x=" << x << " y=" << y << " z=" << z << endl;

    tukarPointer(&x, &y, &z);
    cout << "Setelah tukar (Pointer): x=" << x << " y=" << y << " z=" << z << endl;

    tukarReference(x, y, z);
    cout << "Setelah tukar (Reference): x=" << x << " y=" << y << " z=" << z << endl;

    return 0;
}
