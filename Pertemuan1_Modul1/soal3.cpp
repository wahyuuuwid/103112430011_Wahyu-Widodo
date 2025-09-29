#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;

    cout << "Output:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= i; j--) {
            cout << j << " ";
        }
        cout << "= ";
        for (int j = i; j <= n; j++) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
