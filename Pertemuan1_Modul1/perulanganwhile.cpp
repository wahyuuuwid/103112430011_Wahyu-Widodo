#include <iostream>
using namespace std;

int main(){
    int angka1,angka2;
    cout << "Masukan angka1 : ";
    cin >> angka1;
    // cout << "Masukan angka2 : ";
    // cin >> angka2;

    int i = 0;
    int j = 11;

    //perulangan while
    while (i < angka1){
        cout << i << " - ";
        i++; //increment
    }

    cout << endl;

    //perulangan do while
    do{
        cout << j << " - ";
        j++; //increment
    } while(j < angka1);

    return 0;
}