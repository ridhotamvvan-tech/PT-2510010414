#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    const double BOBOT_HADIR = 0.10;
    const double BOBOT_TUGAS = 0.45;
    const double BOBOT_TENGAH = 0.25;
    const double BOBOT_AKHIR = 0.20;

    int total_mhs = 0;
    cout << "=== Sistem Penilaian v0.6 ===\n";

    cout << "Banyak mahasiswa (minimal 1): ";
    cin >> total_mhs;

    while (cin.fail() || total_mhs < 1) {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Jumlah keliru. Silakan ketik ulang: ";
        cin >> total_mhs;
    }

    cin.ignore(1000, '\n');

    cout << fixed << setprecision(2);

    double akumulasi_nilai = 0;
    int jml_lulus = 0;
    int count_a = 0;
    int count_b = 0;
    int count_c = 0;
    int count_d = 0;
    int count_e = 0;
    double skor_maks = -1;
    string nama_terbaik;

    for (int idx = 1; idx <= total_mhs; idx++) {
        string nama_lengkap;
        string id_npm;
        double hadir = 0;
        double tugas = 0;
        double uts = 0;
        double uas = 0;

        cout << "\n--- Data Pelajar ke-" << idx << " dari "
             << total_mhs << " ---\n";

        do {
            cout << "Nama      : ";
            getline(cin, nama_lengkap);

            bool kosong = true;
            bool ada_angka = false;

            for (char ch : nama_lengkap) {
                unsigned char c = static_cast<unsigned char>(ch);

                if (!isspace(c)) {
                    kosong = false;
                }

                if (isdigit(c)) {
                    ada_angka = true;
                }
            }

            if (kosong) {
                cout << "Nama wajib diisi.\n";
            } else if (ada_angka) {
                cout << "Nama tidak boleh memakai angka.\n";
            }

            if (kosong || ada_angka) {
                nama_lengkap.clear();
            }

        } while (nama_lengkap.empty());

        bool awal_kata = true;

        for (char &ch : nama_lengkap) {
            unsigned char c = static_cast<unsigned char>(ch);

            if (isspace(c)) {
                awal_kata = true;
            } else {
                if (awal_kata) {
                    ch = static_cast<char>(toupper(c));
                    awal_kata = false;
                } else {
                    ch = static_cast<char>(tolower(c));
                }
            }
        }

        cout << "NPM       : ";
        getline(cin, id_npm);

        cout << "Kehadiran : ";
        cin >> hadir;

        while (cin.fail() || hadir < 0 || hadir > 100) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Harus berupa angka 0 s.d. 100. Kehadiran: ";
            cin >> hadir;
        }

        cout << "Mingguan  : ";
        cin >> tugas;

        while (cin.fail() || tugas < 0 || tugas > 100) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Harus berupa angka 0 s.d. 100. Mingguan: ";
            cin >> tugas;
        }

        cout << "UTS       : ";
        cin >> uts;

        while (cin.fail() || uts < 0 || uts > 100) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Harus berupa angka 0 s.d. 100. UTS: ";
            cin >> uts;
        }

        cout << "UAS       : ";
        cin >> uas;

        while (cin.fail() || uas < 0 || uas > 100) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Harus berupa angka 0 s.d. 100. UAS: ";
            cin >> uas;
        }

        cin.ignore(1000, '\n');

        double skor_akhir =
            hadir * BOBOT_HADIR +
            tugas * BOBOT_TUGAS +
            uts * BOBOT_TENGAH +
            uas * BOBOT_AKHIR;

        string predikat;

        if (skor_akhir >= 80) {
            predikat = "A";
        } else if (skor_akhir >= 75) {
            predikat = "B+";
        } else if (skor_akhir >= 70) {
            predikat = "B";
        } else if (skor_akhir >= 65) {
            predikat = "C+";
        } else if (skor_akhir >= 60) {
            predikat = "C";
        } else if (skor_akhir >= 40) {
            predikat = "D";
        } else {
            predikat = "E";
        }

        bool status_lulus = skor_akhir >= 60;

        cout << "  " << left << setw(20) << nama_lengkap
             << right << setw(7) << skor_akhir
             << "  " << left << setw(3) << predikat;

        if (status_lulus) {
            cout << "Lulus\n";
        } else {
            cout << "Belum lulus\n";
        }

        akumulasi_nilai += skor_akhir;

        if (status_lulus) {
            jml_lulus++;
        }

        switch (predikat[0]) {
            case 'A':
                count_a++;
                break;
            case 'B':
                count_b++;
                break;
            case 'C':
                count_c++;
                break;
            case 'D':
                count_d++;
                break;
            default:
                count_e++;
        }

        if (skor_akhir > skor_maks) {
            skor_maks = skor_akhir;
            nama_terbaik = nama_lengkap;
        }
    }

    cout << "\n=== Rekapitulasi Kelas ===\n";
    cout << "Total mahasiswa  : " << total_mhs << "\n";
    cout << "Tuntas           : " << jml_lulus << "\n";
    cout << "Belum tuntas     : "
         << total_mhs - jml_lulus << "\n";
    cout << "Rata-rata kelas  : "
         << akumulasi_nilai / total_mhs << "\n";
    cout << "Nilai tertinggi  : " << nama_terbaik
         << " (" << skor_maks << ")\n";

    cout << "\nDistribusi predikat nilai:\n";

    for (char huruf = 'A'; huruf <= 'E'; huruf++) {
        int frekuensi = 0;

        if (huruf == 'A') {
            frekuensi = count_a;
        } else if (huruf == 'B') {
            frekuensi = count_b;
        } else if (huruf == 'C') {
            frekuensi = count_c;
        } else if (huruf == 'D') {
            frekuensi = count_d;
        } else {
            frekuensi = count_e;
        }

        cout << huruf << " | ";

        for (int j = 1; j <= frekuensi; j++) {
            cout << "#";
        }

        cout << " " << frekuensi << "\n";
    }

    return 0;
}