#include <iostream>
using namespace std;

int main(){
    int angka1,angka2;
    cout << "Masukkan angka1 : ";
    cin >> angka1;
    cout << "Masukkan angka2 : ";
    cin >> angka2;

    if (angka1 > angka2) {
        cout << angka1 << " lebih besar dari " << angka2 << endl;
    } else if (angka1 == angka2) {
        cout << angka1 << " sama dengan " << angka2 << endl;
    } else if (angka1 < angka2) {
        cout << angka1 << " lebih kecil dari " << angka2 << endl;        
    } 

    if (angka1 != angka2) {
        cout << angka1 << " tidak sama dengan " << angka2 << endl;
    }

    return 0;
}