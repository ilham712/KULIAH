#include <iostream>
#include <string>
using namespace std;

// ====== Deklarasi fungsi ======
bool cekRefleksif(string himp[], int n, string relasi[][2], int m);
bool cekSimetris(string relasi[][2], int m);
bool cekTransitif(string relasi[][2], int m);

int main() {
    int jumlahHimpunan;
    cout << "Masukkan jumlah himpunan: ";
    cin >> jumlahHimpunan;

    const int MAKS_ELEMEN = 100;
    string namaHimpunan[jumlahHimpunan];
    int jumlahElemen[jumlahHimpunan];
    string isiHimpunan[jumlahHimpunan][MAKS_ELEMEN];

    cout << endl;

    // Input semua himpunan
    for (int i = 0; i < jumlahHimpunan; i++) {
		// Input semua nama himpunan sebanyak jumlah himpunan
        cout << "Masukkan nama himpunan ke-" << (i + 1) << ": ";
        cin >> namaHimpunan[i];
		
		// Input jumlah elemen tiap himpunan
        cout << "Masukkan jumlah elemen himpunan " << namaHimpunan[i] << ": ";
        cin >> jumlahElemen[i];
		
		// Input elemen-elemen tiap himpunan sebanyak jumlah elemen tiap himpunan
        cout << "Masukkan elemen-elemen himpunan " << namaHimpunan[i] << ":\n";
        for (int j = 0; j < jumlahElemen[i]; j++) {
            cout << "Elemen ke-" << (j + 1) << ": ";
            cin >> isiHimpunan[i][j];
        }

        // Tampilkan hasil input himpunan
        cout << "Anggota himpunan " << namaHimpunan[i] << " = { ";
        for (int j = 0; j < jumlahElemen[i]; j++) {
            cout << isiHimpunan[i][j];
            if (j < jumlahElemen[i] - 1) cout << ", ";
        }
        cout << " }\n\n";
    } 
	
	// Input jumlah relasi
    int jumlahRelasi;
    cout << "\nMasukkan jumlah relasi yang ingin dibuat: ";
    cin >> jumlahRelasi;

    for (int r = 0; r < jumlahRelasi; r++) {
        cout << "\n=== Relasi ke-" << (r + 1) << " ===\n";

        // ===== Pilih domain dan kodomain =====
        string namaDomain, namaKodomain;
        cout << "Pilih himpunan sebagai DOMAIN: ";
        cin >> namaDomain;
        cout << "Pilih himpunan sebagai KODOMAIN: ";
        cin >> namaKodomain;

        int idxDomain = -1, idxKodomain = -1;
        for (int i = 0; i < jumlahHimpunan; i++) {
            if (namaHimpunan[i] == namaDomain) {
				idxDomain = i;
			}
            if (namaHimpunan[i] == namaKodomain) {
				idxKodomain = i;
			}
        }

        if (idxDomain == -1 || idxKodomain == -1) {
            cout << "Himpunan tidak ditemukan!\n";
            continue;
        }

        int nDom = jumlahElemen[idxDomain];
        int nKod = jumlahElemen[idxKodomain];
        int m = 0;
        string (*relasi)[2] = new string[nDom * nKod][2];

        // ===== Pilih jenis relasi =====
        cout << "Pilih jenis relasi:\n";
        cout << "1. Relasi lengkap (semua pasangan mungkin)\n";
        cout << "2. Relasi manual (anda yang menentukan)\n";
        cout << "Pilihan: ";
        int jenis;
        cin >> jenis;

        if (jenis == 1) {
            for (int i = 0; i < nDom; i++) {
                for (int j = 0; j < nKod; j++) {
                    relasi[m][0] = isiHimpunan[idxDomain][i];
                    relasi[m][1] = isiHimpunan[idxKodomain][j];
                    m++;
                }
            }
        } else {
            cout << "Masukkan jumlah pasangan relasi: ";
            cin >> m;
            cout << "Masukkan pasangan relasi (format: a, b):\n";
            for (int i = 0; i < m; i++) {
                cout << "Pasangan ke-" << (i + 1) << ": ";
                cin >> relasi[i][0] >> relasi[i][1];
            }
        }

        // ===== Tampilkan relasi =====
        cout << "\nRelasi R dari " << namaDomain << " ke " << namaKodomain << ":\nR = { ";
        for (int i = 0; i < m; i++) {
            cout << "(" << relasi[i][0] << "," << relasi[i][1] << ")";
            if (i < m - 1) cout << ", ";
        }
        cout << " }\n\n";

        // ===== Cek semua sifat relasi tanpa peduli domain/kodomain =====
        bool refleksif = cekRefleksif(isiHimpunan[idxDomain], nDom, relasi, m);
        bool simetris = cekSimetris(relasi, m);
        bool transitif = cekTransitif(relasi, m);

        cout << "Sifat-sifat relasi:\n";
        cout << "Refleksif ?\nSimetris ?\nTransitif ?\n\n";
        system("pause");

        cout << "Refleksif Untuk semua a termasuk anggota himpunan A, relasi R pada\n";
        cout << "himpunan A disebut refleksif jika (a, a) termasuk anggota relasi R.\n";
        cout << "Refleksif: " << (refleksif ? "YAA" : "TIDAKK") << "\n\n";
        system("pause");

        cout << "Untuk semua a, b termasuk anggota himpunan A,\n";
        cout << "relasi R pada himpunan A disebut setangkup\n";
        cout << "jika setiap (a, b) termasuk anggota relasi R,\n";
        cout << "maka harus ada (b, a) termasuk anggota relasi R.\n";
        cout << "Simetris : " << (simetris ? "YAA" : "TIDAKK") << "\n\n";
        system("pause");

        cout << "Untuk semua a, b, c termasuk anggota himpunan A,\n";
        cout << "relasi R pada himpunan A disebut menghantar\n";
        cout << "jika (a, b) temasuk anggota relasi R\n";
        cout << "dan (b, c) termasuk anggota relasi R,\n";
        cout << "maka (a, c) termasuk anggota relasi R.\n";
        cout << "Transitif: " << (transitif ? "YAA" : "TIDAKK") << "\n\n";
        system("pause");

        cout << "=== Cek relasi ekuivalen (setara) ===\n";
        cout << "Suatu relasi P pada suatu himpunan S disebut relasi setara\n";
        cout << "atau relasi ekivalen (equivalence relation) pada himpunan S\n";
        cout << "apabila P bersifat refleksif, simetris dan transitif.\n";
        system("pause");

        if (refleksif && simetris && transitif) {
            cout << "\nRelasi ini merupakan relasi EKUIVALEN (SETARA).\n";
        } else {
            cout << "Relasi ini bukan relasi EKUIVALEN (SETARA).\n";
        }

        delete[] relasi;
    }

    return 0;
}

// ===== Fungsi-fungsi cek sifat relasi =====

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
