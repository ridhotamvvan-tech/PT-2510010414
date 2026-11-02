#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    const double BOBOT_KEHADIRAN = 0.10;
    const double BOBOT_MINGGUAN = 0.45;
    const double BOBOT_UTS = 0.25;
    const double BOBOT_UAS = 0.20;

    int jumlah_mahasiswa = 0;

    cout << "=== SiNilai v0.5 ===\n";

    do {
        cout << "Jumlah mahasiswa (paling sedikit 1): ";
        cin >> jumlah_mahasiswa;
    } while (jumlah_mahasiswa < 1);

    // TODO 1: Mengatur angka pecahan menjadi dua angka desimal
    cout << fixed << setprecision(2);

    double total_nilai = 0;
    int jumlah_lulus = 0;

    // TODO 2: Penghitung huruf mutu
    int jumlah_a = 0;
    int jumlah_b = 0;
    int jumlah_c = 0;
    int jumlah_d = 0;
    int jumlah_e = 0;

    // TODO 3: Menyimpan mahasiswa dengan nilai tertinggi
    double nilai_tertinggi = -1;
    string nama_tertinggi;

    for (int i = 1; i <= jumlah_mahasiswa; i++) {
        string nama;
        string npm;

        double kehadiran = 0;
        double mingguan = 0;
        double uts = 0;
        double uas = 0;

        cout << "\n--- Mahasiswa ke-" << i
             << " dari " << jumlah_mahasiswa << " ---\n";

        cout << "Nama      : ";
        getline(cin >> ws, nama);

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

        double nilai_akhir =
            kehadiran * BOBOT_KEHADIRAN +
            mingguan * BOBOT_MINGGUAN +
            uts * BOBOT_UTS +
            uas * BOBOT_UAS;

        string huruf_mutu;

        if (nilai_akhir >= 80) {
            huruf_mutu = "A";
        } else if (nilai_akhir >= 75) {
            huruf_mutu = "B+";
        } else if (nilai_akhir >= 70) {
            huruf_mutu = "B";
        } else if (nilai_akhir >= 65) {
            huruf_mutu = "C+";
        } else if (nilai_akhir >= 60) {
            huruf_mutu = "C";
        } else if (nilai_akhir >= 40) {
            huruf_mutu = "D";
        } else {
            huruf_mutu = "E";
        }

        bool lulus = nilai_akhir >= 60;

        // TODO 4: Menampilkan kartu nilai dalam satu baris berkolom
        cout << "\n--- Kartu Nilai Mahasiswa ---\n";

        cout << "  "
             << left << setw(20) << nama
             << right << setw(7) << nilai_akhir
             << "  "
             << left << setw(3) << huruf_mutu;

        if (lulus) {
            cout << "Lulus\n";
        } else {
            cout << "Belum lulus\n";
        }

        // Menghitung total nilai
        total_nilai += nilai_akhir;

        // Menghitung jumlah mahasiswa yang lulus
        if (lulus) {
            jumlah_lulus++;
        }

        // TODO 5: Menghitung jumlah mahasiswa berdasarkan huruf mutu
        switch (huruf_mutu[0]) {
            case 'A':
                jumlah_a++;
                break;

            case 'B':
                jumlah_b++;
                break;

            case 'C':
                jumlah_c++;
                break;

            case 'D':
                jumlah_d++;
                break;

            default:
                jumlah_e++;
                break;
        }

        // TODO 6: Menentukan mahasiswa dengan nilai tertinggi
        if (nilai_akhir > nilai_tertinggi) {
            nilai_tertinggi = nilai_akhir;
            nama_tertinggi = nama;
        }
    }

    // Laporan kelas
    cout << "\n=== Laporan Kelas ===\n";

    cout << "Jumlah mahasiswa : " << jumlah_mahasiswa << "\n";
    cout << "Lulus            : " << jumlah_lulus << "\n";
    cout << "Belum lulus      : "
         << jumlah_mahasiswa - jumlah_lulus << "\n";

    cout << "Rata-rata kelas  : "
         << total_nilai / jumlah_mahasiswa << "\n";

    // TODO 7: Menampilkan mahasiswa dengan nilai tertinggi
    cout << "Tertinggi        : "
         << nama_tertinggi << " (" << nilai_tertinggi << ")\n";

    // Rekapitulasi sebaran huruf mutu
    cout << "\nSebaran huruf mutu:\n";

    for (char huruf = 'A'; huruf <= 'E'; huruf++) {
        int banyak = 0;

        // TODO 8: Menentukan jumlah mahasiswa untuk setiap huruf
        if (huruf == 'A') {
            banyak = jumlah_a;
        } else if (huruf == 'B') {
            banyak = jumlah_b;
        } else if (huruf == 'C') {
            banyak = jumlah_c;
        } else if (huruf == 'D') {
            banyak = jumlah_d;
        } else {
            banyak = jumlah_e;
        }

        cout << huruf << " | ";

        // TODO 9: Menggambar batang menggunakan perulangan bersarang
        for (int j = 0; j < banyak; j++) {
            cout << "#";
        }

        cout << " " << banyak << "\n";
    }

    return 0;
}