#include <iostream>
#include <string>
using namespace std;

// ===== Deklarasi Fungsi =====
bool cekRefleksif(string himp[], int n, string relasi[][2], int m);
bool cekSimetris(string relasi[][2], int m);
bool cekTransitif(string relasi[][2], int m);

// =============================
// ==========   MAIN   =========
// =============================
int main() {
    const int MAKS_ELEMEN = 100;
    int jumlahHimpunan;
    string soal;

	cout << "Silakan masukkan soalnya: ";
	getline(cin,soal);
	cout << endl;
    cout << "Masukkan jumlah himpunan: ";
    cin >> jumlahHimpunan;

    string namaHimpunan[jumlahHimpunan];
    int jumlahElemen[jumlahHimpunan];
    string isiHimpunan[jumlahHimpunan][MAKS_ELEMEN];

    // ===== INPUT HIMPUNAN =====
    for (int i = 0; i < jumlahHimpunan; i++) {
        cout << "\nMasukkan nama himpunan ke-" << i + 1 << ": ";
        cin >> namaHimpunan[i];

        cout << "Masukkan jumlah elemen: ";
        cin >> jumlahElemen[i];

        cout << "Masukkan elemen-elemen himpunan:\n";
        for (int j = 0; j < jumlahElemen[i]; j++) {
            cout << "  Elemen ke-" << j + 1 << ": ";
            cin >> isiHimpunan[i][j];
        }

        cout << "Himpunan " << namaHimpunan[i] << " = { ";
        for (int j = 0; j < jumlahElemen[i]; j++) {
            cout << isiHimpunan[i][j];
            if (j < jumlahElemen[i] - 1) cout << ", ";
        }
        cout << " }\n";
    }

    // ===== JUMLAH RELASI =====
    int jumlahRelasi;
    cout << "\nMasukkan jumlah relasi: ";
    cin >> jumlahRelasi;

    for (int r = 0; r < jumlahRelasi; r++) {
        cout << "\n=== Relasi ke-" << r + 1 << " ===\n";

        // ===== PILIH DOMAIN & KODOMAIN =====
        string namaDomain, namaKodomain;
        cout << "Pilih DOMAIN   : ";
        cin >> namaDomain;
        cout << "Pilih KODOMAIN : ";
        cin >> namaKodomain;

        int idxDomain = -1, idxKodomain = -1;
        //mengecek apakah domain dan kodomain sesuai dengan nama himpunan yang diinput 
        for (int i = 0; i < jumlahHimpunan; i++) {
            if (namaHimpunan[i] == namaDomain) {
				idxDomain = i ;
			}
            if (namaHimpunan[i] == namaKodomain) {
				idxKodomain = i;
			}
        }
		//jika input domain atau kodomain tidak sesuai dengan nama himpunan yang diinput
        if (idxDomain == -1 || idxKodomain == -1) {
            cout << "Himpunan tidak ditemukan!\n";
            continue;
        }

        int nDom = jumlahElemen[idxDomain];
        int nKod = jumlahElemen[idxKodomain];
      // ===== TANPA NEW, PAKAI ARRAY BIASA =====
        const int MAX_RELASI = 100;
        string relasi[MAX_RELASI][2];
        int m = 0;

        // ===== PILIH JENIS RELASI =====
        cout << "1. Relasi lengkap\n2. Relasi manual\nPilihan: ";
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
            cout << "Masukkan pasangan (format : a b)\n";
            for (int i = 0; i < m; i++) {
				bool valid = false;
				while (!valid) {
					cout << "Pasangan ke-" << i + 1 << " : ";
					cin >> relasi[i][0] >> relasi[i][1];

					bool adaDiDomain = false;
					bool adaDiKodomain = false;

					// cek apakah elemen pertama ada di domain
					for (int d = 0; d < nDom; d++) {
						if (relasi[i][0] == isiHimpunan[idxDomain][d]) {
							adaDiDomain = true;
							break;
						}
					}

					// cek apakah elemen kedua ada di kodomain
					for (int k = 0; k < nKod; k++) {
						if (relasi[i][1] == isiHimpunan[idxKodomain][k]) {
							adaDiKodomain = true;
							break;
						}
					}

					if (!adaDiDomain || !adaDiKodomain) {
						cout << endl;
						cout << "ERROR: Elemen tidak sesuai domain/kodomain!\n";
						cout << "  - Elemen pertama HARUS anggota himpunan " << namaDomain << "\n";
						cout << "  - Elemen kedua  HARUS anggota himpunan " << namaKodomain << "\n";
						cout << "Silakan input ulang.\n\n";
					} else {
						valid = true;
					}
				}
			}

        }

        // ===== TAMPILKAN RELASI =====
        cout << "\nRelasi R:\nR = { ";
        for (int i = 0; i < m; i++) {
            cout << "(" << relasi[i][0] << "," << relasi[i][1] << ")";
            if (i < m - 1) cout << ", ";
        }
        cout << " }\n\n";

        // ===== CEK SIFAT RELASI =====
        bool refleksif = cekRefleksif(isiHimpunan[idxDomain], nDom, relasi, m);
        bool simetris  = cekSimetris(relasi, m);
        bool transitif = cekTransitif(relasi, m);

        // === PENJELASAN ===
        system("pause");
        cout << "Sifat-sifat relasi:\n";
		cout << "Refleksif ?\nSimetris ?\nTransitif ?\n\n";
		system ("pause");
		cout <<"Refleksif Untuk semua a termasuk anggota himpunan A, relasi R pada" << endl
			   << "himpunan A disebut refleksif jika (a, a) termasuk anggota relasi R.\n";
        cout << "Hasil Refleksif: " << (refleksif ? "YAA" : "TIDAKK") << "\n\n";

        system("pause");
		cout << "Simetris Untuk semua a, b termasuk anggota himpunan A," << endl
			   << "relasi R pada himpunan A disebut setangkup" << endl
			   << "jika setiap (a, b) termasuk anggota relasi R," << endl
			   << "maka harus ada (b, a) termasuk anggota relasi R.\n";
        cout << "Hasil Simetris : " << (simetris ? "YAA" : "TIDAKK") << "\n\n";

        system("pause");
		cout << "Transitif Untuk semua a, b, c termasuk anggota himpunan A," << endl 
			   << "relasi R pada himpunan A disebut menghantar " << endl
			   << "jika (a, b) temasuk anggota relasi R" << endl
			   << "dan (b, c) termasuk anggota relasi R," << endl 
			   << "maka (a, c) termasuk anggota relasi R.\n";
        cout << "Hasil Transitif: " << (transitif ? "YAA" : "TIDAKK") << "\n\n";

        // ===== CEK EKUIVALEN =====
        system("pause");
		cout << "=== Cek relasi ekuivalen (setara) ===\n";
		cout << "Suatu relasi P pada suatu himpunan S disebut relasi setara \n";
		cout << "atau relasi ekivalen (equivalence relation) pada himpunan S \n";
		cout << "apabila P bersifat refleksif, simetris dan transitif. \n";

        if (refleksif && simetris && transitif)
            cout << "Relasi ini adalah RELASI EKUIVALEN.\n";
        else
            cout << "Relasi ini BUKAN relasi ekuivalen.\n";

       
    }

    return 0;
}

// =============================
// ====== Fungsi Cek Sifat =====
// =============================
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
        if (!found) return false;
    }
    return true;
}

bool cekSimetris(string relasi[][2], int m) {
    for (int i = 0; i < m; i++) {
        string a = relasi[i][0];
        string b = relasi[i][1];
        bool pasanganBalik = false;

        for (int j = 0; j < m; j++) {
            if (relasi[j][0] == b && relasi[j][1] == a) {
                pasanganBalik = true;
                break;
            }
        }
        if (!pasanganBalik) return false;
    }
    return true;
}

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
                if (!ada_ac) return false;
            }
        }
    }
    return true;
}
