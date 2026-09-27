#include <iostream>

int main() {
    int total = 240;
    int jumlah_mahasiswa = 0;
    std::cout << "Jumlah mahasiswa: ";
    std::cin >> jumlah_mahasiswa;
    int rerata = total / jumlah_mahasiswa;
    std::cout << "Rata-rata: " << rerata << "\n";
    return 0;
}
