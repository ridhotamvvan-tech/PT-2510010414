#include <iostream>

using namespace std;

int main() {
    int bilangan1, bilangan2;
    int hasil_bagi, sisa;

    cout << "Bilangan pertama : ";
    cin >> bilangan1;

    cout << "Bilangan kedua   : ";
    cin >> bilangan2;

    hasil_bagi = bilangan1 / bilangan2;
    sisa = bilangan1 % bilangan2;

    cout << bilangan1 << " dibagi " << bilangan2
         << " adalah " << hasil_bagi
         << " sisa " << sisa << endl;

    return 0;
}