#include<iostream>
using namespace std;

int main(){
    int angka1,angka2;
    cout << "Masukkan angka1 : ";
    cin >> angka1;
    cout << "Masukkan angka2 : ";
    cin >> angka2;

    for (int i = 0; i < angka1; i++){ // increment
        cout << i << " - ";
    }

    cout << endl;

    for (int i = 20; i > angka2; i--){ // decrement
        cout << i << " - ";
    }

    return 0;
}