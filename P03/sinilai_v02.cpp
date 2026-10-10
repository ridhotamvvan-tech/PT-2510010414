#include <iostream>
#include <string>

using namespace std;

int main() {

    const double BOBOT_KEHADIRAN = 0.10;
    const double BOBOT_MINGGUAN = 0.20;
    const double BOBOT_UTS = 0.30;
    const double BOBOT_UAS = 0.40;

    string nama;
    string npm;
    double kehadiran = 0;
    double mingguan = 0;
    double uts = 0;
    double uas = 0;

    double nilai_akhir = 0;
    double rerata_polos = 0;
    double selisih = 0;

    cout << "=== SiNilai v0.2 ===\n";
    cout << "Nama      : ";
    getline(cin, nama);

    cout << "NPM       : ";
    cin >> npm;

    cout << "Kehadiran : ";
    cin >> kehadiran;

    cout << "Mingguan  : ";
    cin >> mingguan;

    cout << "UTS       : ";
    cin >> uts;

    cout << "UAS       : ";
    cin >> uas;

    nilai_akhir = (kehadiran * BOBOT_KEHADIRAN) +
                   (mingguan * BOBOT_MINGGUAN) +
                   (uts * BOBOT_UTS) +
                   (uas * BOBOT_UAS);

    rerata_polos = (kehadiran + mingguan + uts + uas) / 4;

    selisih = nilai_akhir - rerata_polos;

    cout << "\n--- Kartu Nilai Mahasiswa ---\n";
    cout << "Nama          : " << nama << "\n";
    cout << "NPM           : " << npm << "\n";
    cout << "Nilai Akhir   : " << nilai_akhir << "\n";
    cout << "Rerata Polos  : " << rerata_polos << "\n";
    cout << "Selisih       : " << selisih << "\n";

    return 0;
}