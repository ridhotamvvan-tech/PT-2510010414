#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Dua bilangan bulat: ";
    cin >> a >> b;

    if (b == 0) {
        cout << "Pembagi tidak boleh nol\n";
        return 1;
    }
    cout << a << " dibagi " << b << " adalah "
         << a / b << " sisa " << a % b << "\n";
}