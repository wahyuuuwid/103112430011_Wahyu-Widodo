#include<iostream>
using namespace std;

int main(){
    int angka1, angka2;
    cout << "Masukkan angka1 : "; 
    cin >> angka1;
    cout << "Masukkan angka2 : ";
    cin >> angka2;

    //penjumlahan
    cout << "Penjumalah : " << angka1 + angka2 << endl;
    //pengurangan
    cout << "Pengurangan : " << angka1 - angka2 << endl;
    //perkalian
    cout << "Perkalian : " << angka1 * angka2 << endl;
    //pembagian
    cout << "Pembagian : " << angka1 / angka2 << endl;
    //modulus
    cout << "Modulus : " << angka1 % angka2 << endl;
    return 0;
}
