#include <iostream>
using namespace std;

string angkaSatuan[] = {
    "nol", "satu", "dua", "tiga", "empat", "lima", 
    "enam", "tujuh", "delapan", "sembilan"
};

string angkaBelasan[] = {
    "sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas",
    "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"
};

string angkaPuluhan[] = {
    "", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh",
    "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"
};

string bilangan(int n) {
    if (n < 10) return angkaSatuan[n];
    else if (n < 20) return angkaBelasan[n - 10];
    else if (n < 100) {
        int puluh = n / 10;
        int satuan = n % 10;
        if (satuan == 0) return angkaPuluhan[puluh];
        else return angkaPuluhan[puluh] + " " + angkaSatuan[satuan];
    } else if (n == 100) return "seratus";
    else return "di luar jangkauan";
}

int main() {
    int n;
    cout << "Masukkan angka (0-100): ";
    cin >> n;

    if (n < 0 || n > 100)
        cout << "Input tidak valid!" << endl;
    else
        cout << n << " : " << bilangan(n) << endl;

    return 0;
}
