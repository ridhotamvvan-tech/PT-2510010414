#include <iostream>

int main() {
    int kehadiran = 90;
    int tugas = 80;
    int praktikum = 85;
    int uts = 75;
    int uas = 90;

    double rerata = (kehadiran + tugas + praktikum + uts + uas) / 5.0;

    std::cout << "Rata-rata : " << rerata << "\n";
    return 0;
}