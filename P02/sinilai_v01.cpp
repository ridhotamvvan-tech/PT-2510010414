// SiNilai v0.1: data satu mahasiswa.
// Program membaca nama, NPM, dan empat komponen nilai, lalu menampilkannya sebagai kartu.
// Versi ini belum menghitung apa-apa; itu tugas Pertemuan 3.

#include <iostream>
#include <string>

using namespace std;

int main() {
    // TODO 1: variabel nama dan NPM
    string nama;
    string npm;

    // TODO 2: empat variabel nilai
    double kehadiran;
    double mingguan;
    double uts;
    double uas;

    cout << "=== SiNilai v0.1 ===\n";

    cout << "Nama : ";
    // TODO 3: baca nama dengan spasi
    getline(cin, nama);

    cout << "NPM : ";
    // TODO 4: baca NPM
    cin >> npm;

    // TODO 5: baca keempat komponen nilai
    cout << "Kehadiran : ";
    cin >> kehadiran;

    cout << "Mingguan : ";
    cin >> mingguan;

    cout << "UTS : ";
    cin >> uts;

    cout << "UAS : ";
    cin >> uas;

    cout << "\n--- Kartu Data Mahasiswa ---\n";

    // TODO 6: tampilkan semua data
    cout << "Nama       : " << nama << endl;
    cout << "NPM        : " << npm << endl;
    cout << "Kehadiran  : " << kehadiran << endl;
    cout << "Mingguan    : " << mingguan << endl;
    cout << "UTS        : " << uts << endl;
    cout << "UAS        : " << uas << endl;

    return 0;
}