#include <iostream>
using namespace std;

int main() {
    // Input himpunan asal
    int n;
    cout << "Masukkan jumlah anggota himpunan asal: ";
    cin >> n;
    int himp[n];

    for (int i = 0; i < n; i++) {
        cout << "Masukkan anggota himpunan asal ke-" << (i + 1) << ": ";
        cin >> himp[i];
    }

    cout << "Anggota himpunan asal = { ";
    for (int i = 0; i < n; i++) {
        cout << himp[i] << " ";
    }
    cout << "}\n\n";

    // Input relasi
    int m;
    cout << "Masukkan jumlah pasangan dalam relasi: ";
    cin >> m;
    int relasi[m][2];

    cout << "Format: masukkan dua elemen yang berelasi (misal: 1 2)\n";
    for (int i = 0; i < m; i++) {
        cout << "Masukkan pasangan relasi ke-" << (i + 1) << ": ";
        cin >> relasi[i][0] >> relasi[i][1];
    }

    cout << "Relasi = {";
    for (int i = 0; i < m; i++) {
        cout << "(" << relasi[i][0] << "," << relasi[i][1] << ")";
        if (i < m - 1) cout << ", ";
    }
    cout << "}\n\n";

    // === 1. Cek Refleksif ===
    bool refleksif = true;
    for (int i = 0; i < n; i++) {
        int x = himp[i];
        bool found = false;
        for (int j = 0; j < m; j++) {
            if (relasi[j][0] == x && relasi[j][1] == x) {
                found = true;
                break;
            }
        }
        if (!found) {
            refleksif = false;
            break;
        }
    }

    // === 2. Cek Simetris ===
    bool simetris = true;
    for (int i = 0; i < m; i++) {
        int a = relasi[i][0];
        int b = relasi[i][1];
        bool pasanganBalikAda = false;

        // Cari apakah (b, a) ada di relasi
        for (int j = 0; j < m; j++) {
            if (relasi[j][0] == b && relasi[j][1] == a) {
                pasanganBalikAda = true;
                break;
            }
        }

        if (!pasanganBalikAda) {
            simetris = false;
            break;
        }
    }

    // === 3. Cek Transitif ===
    bool transitif = true;
    for (int i = 0; i < m; i++) {
        int a = relasi[i][0];
        int b = relasi[i][1];

        // Cari semua pasangan yang dimulai dari b: (b, c)
        for (int j = 0; j < m; j++) {
            if (relasi[j][0] == b) {
                int c = relasi[j][1];
                // Sekarang periksa apakah (a, c) ada
                bool acAda = false;
                for (int k = 0; k < m; k++) {
                    if (relasi[k][0] == a && relasi[k][1] == c) {
                        acAda = true;
                        break;
                    }
                }
                if (!acAda) {
                    transitif = false;
                    goto selesai_transitif; // keluar dari nested loop
                }
            }
        }
    }
    selesai_transitif:

    // === Tampilkan Hasil ===
    cout << "Sifat-sifat relasi:\n";
    cout << "- Refleksif: " << (refleksif ? "Ya" : "Tidak") << endl;
    cout << "- Simetris : " << (simetris ? "Ya" : "Tidak") << endl;
    cout << "- Transitif: " << (transitif ? "Ya" : "Tidak") << endl;
    
     // === Cek relasi ekuivalen (setara) ===
    if (refleksif && simetris && transitif) {
        cout << "\nRelasi ini merupakan relasi EKUIVALEN (SETARA).\n";
    }
    else cout<<"Relasi ini bukan relasi EKUIVALEN (SETARA).\n";


    return 0;
}
