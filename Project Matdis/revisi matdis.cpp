#include <iostream>
#include <string>
using namespace std;

// ====== Deklarasi fungsi ======
bool cekRefleksif(string himp[], int n, string relasi[][2], int m);
bool cekSimetris(string relasi[][2], int m);
bool cekTransitif(string relasi[][2], int m);

int main() {
    int n;
    cout << "Silakan Masukkan jumlah anggota himpunan asal : ";
    cin >> n;
    string himp[n];

    for (int i = 0; i < n; i++) {
        cout << "Masukkan anggota himpunan asal ke-" << (i + 1) << ": ";
        cin >> himp[i];
    }

    cout << "Anggota himpunan asal = { ";
    for (int i = 0; i < n; i++) {
        cout << himp[i];
        if (i < n - 1) cout << ", ";
    }
    cout << " }\n\n";

    // === Tambahan: Pilih mode input relasi ===
    char pilihanrelasi;
    cout << "Pilih opsi input relasi:\n";
    cout << "M = Input Manual\n";
    cout << "O = Otomatis (relasi EKUIVALEN penuh: semua elemen saling berelasi)\n";
    cout << "Pilihan (M/O): ";
    cin >> pilihanrelasi;

    int m;
    if (pilihanrelasi == 'O' || pilihanrelasi == 'o') {
        // Mode otomatis: relasi penuh (n x n)
        m = n * n;
        string relasi[m][2];
        int idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                relasi[idx][0] = himp[i];
                relasi[idx][1] = himp[j];
                idx++;
            }
        }

        // Tampilkan relasi otomatis
        cout << "\nRelasi otomatis (EKUIVALEN penuh) = {";
        for (int i = 0; i < m; i++) {
            cout << "(" << relasi[i][0] << "," << relasi[i][1] << ")";
            if (i < m - 1) cout << ", ";
        }
        cout << "}\n\n";

       
    }
    else if (pilihanrelasi == 'M' || pilihanrelasi == 'm') {
        // Mode manual
        cout << "Silakan Masukkan jumlah pasangan dalam relasi: ";
        cin >> m;
        string relasi[m][2];

        cout << "Silakan input pasangan relasi dan harus sesuai dengan anggota himpunan asal\n";
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
    } 
    // Cek sifat
    bool refleksif = cekRefleksif(himp, n, relasi, m);
    bool simetris = cekSimetris(relasi, m);
    bool transitif = cekTransitif(relasi, m);
    // Lanjut ke tampil hasil
        cout << "Sifat-sifat relasi:\n";
        cout << "Refleksif ?\nSimetris ?\nTransitif ?\n\n";
        system("pause");
        cout << "Refleksif: Untuk semua a anggota himpunan A, (a,a) harus ada di R.\n";
        cout << "Refleksif: " << (refleksif ? "YAA" : "TIDAKK") << endl << endl;
        system("pause");

        cout << "Simetris: Jika (a,b) ada, maka (b,a) harus ada.\n";
        cout << "Simetris : " << (simetris ? "YAA" : "TIDAKK") << endl << endl;
        system("pause");

        cout << "Transitif: Jika (a,b) dan (b,c) ada, maka (a,c) harus ada.\n";
        cout << "Transitif: " << (transitif ? "YAA" : "TIDAKK") << endl << endl;
        system("pause");

        cout << "=== Cek relasi ekuivalen (setara) ===\n";
        cout << "Relasi ekuivalen harus refleksif, simetris, dan transitif.\n";
        system("pause");

        if (refleksif && simetris && transitif) {
            cout << "\nRelasi ini merupakan relasi EKUIVALEN (SETARA).\n";
        } else {
            cout << "Relasi ini bukan relasi EKUIVALEN (SETARA).\n";
        }

    return 0;
}

// Fungsi cek Refleksif
bool cekRefleksif(string himp[], int n, string relasi[][2], int m) {
    for (int i = 0; i < n; i++) {
        string x = himp[i];
        bool found = false;
        for (int j = 0; j < m; j++) {
            if (relasi[j][0] == x && relasi[j][1] == x) {
                found = true;
                break;
            }
        }
        if (found == false) {
            return false;
        }
    }
    return true;
}

// Fungsi cek Simetris
bool cekSimetris(string relasi[][2], int m) {
    for (int i = 0; i < m; i++) {
        string a = relasi[i][0];
        string b = relasi[i][1];
        bool pasanganbalik = false;
        for (int j = 0; j < m; j++) {
            if (relasi[j][0] == b && relasi[j][1] == a) {
                pasanganbalik = true;
                break;
            }
        }
        if (pasanganbalik == false) {
            return false;
        }
    }
    return true;
}

// Fungsi cek Transitif
bool cekTransitif(string relasi[][2], int m) {
    for (int i = 0; i < m; i++) {
        string a = relasi[i][0];
        string b = relasi[i][1];
        for (int j = 0; j < m; j++) {
            if (relasi[j][0] == b) {
                string c = relasi[j][1];
                bool ada_ac = false;
                for (int k = 0; k < m; k++) {
                    if (relasi[k][0] == a && relasi[k][1] == c) {
                        ada_ac = true;
                        break;
                    }
                }
                if (ada_ac == false) {
                    return false;
                }
            }
        }
    }
    return true;
}
