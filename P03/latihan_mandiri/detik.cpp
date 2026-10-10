#include <iostream>
using namespace std;

int main() {
    int total;
    cout << "Jumlah detik: ";
    cin >> total;

    int jam   = total / 3600;
    int menit = (total % 3600) / 60;
    int detik = total % 60;

    cout << jam << " jam " << menit << " menit " << detik << " detik\n";
}