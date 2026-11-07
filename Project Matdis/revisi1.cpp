#include <iostream>
using namespace std;

// Fungsi cek Refleksif
bool cekRefleksif(int himp[], int n, int relasi[][2], int m) {
    for (int i = 0; i < n; i++) {
        int x = himp[i];
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
bool cekSimetris(int relasi[][2], int m) {
    for (int i = 0; i < m; i++) {
        int a = relasi[i][0];
        int b = relasi[i][1];
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
bool cekTransitif(int relasi[][2], int m) {
    for (int i = 0; i < m; i++) {
        int a = relasi[i][0];
        int b = relasi[i][1];
        for (int j = 0; j < m; j++) {
            if (relasi[j][0] == b) {
                int c = relasi[j][1];
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

 
int main() {
	
    // Input jumlah anggota himpunan asal
    int n;
    cout << "Silakan Masukkan jumlah anggota himpunan asal : ";
    cin >> n;
    int himp[n];

	// Input anggota himpunan asal
    for (int i = 0; i < n; i++) {
        cout << "Masukkan anggota himpunan asal ke-" << (i + 1) << ": ";
        cin >> himp[i];
	}
 
	// Output anggota himpunan asal
    cout << "Anggota himpunan asal = { ";
    for (int i = 0; i < n; i++) {
        cout << himp[i] << " ";
        if (i < n - 1) cout << ", ";
    }
    cout << "}\n\n";

    // Input jumlah pasangan relasi
    int m;
    cout << "Silakan Masukkan jumlah pasangan dalam relasi: ";
    cin >> m;
    int relasi[m][2];

	// Input pasangan relasi 
	cout << "Silakan input pasangan relasi dan harus sesuai dengan anggota himpunan asal\n";
    cout << "Format: masukkan dua elemen yang berelasi (misal: 1 2)\n";
    for (int i = 0; i < m; i++) {
        cout << "Masukkan pasangan relasi ke-" << (i + 1) << ": ";
        cin >> relasi[i][0] >> relasi[i][1];
    }

	// Output pasangan relasi
    cout << "Relasi = {";
    for (int i = 0; i < m; i++) {
        cout << "(" << relasi[i][0] << "," << relasi[i][1] << ")";
        if (i < m - 1) cout << ", ";
    }
    cout << "}\n\n";

                
        // Panggil fungsi
    bool refleksif = cekRefleksif(himp, n, relasi, m);
    bool simetris = cekSimetris(relasi, m);
    bool transitif = cekTransitif(relasi, m);

    // Menampilkan hasil
    cout << "Sifat-sifat relasi:\n";
    cout << "Refleksif ?\nSimetris ?\nTransitif ?\n\n";
    system ("pause");
    cout <<"Refleksif Untuk semua a termasuk anggota himpunan A, relasi R pada" << endl
		 << "himpunan A disebut refleksif jika (a, a) termasuk anggota relasi R.\n";
    cout << "Refleksif: " << (refleksif ? "YAA" : "TIDAKK") << endl << endl;
    system ("pause");
    
    cout << "Untuk semua a, b termasuk anggota himpunan A," << endl
		 << "relasi R pada himpunan A disebut setangkup" << endl
		 << "jika setiap (a, b) termasuk anggota relasi R," << endl
		 << "maka harus ada (b, a) termasuk anggota relasi R.\n";
    cout << "Simetris : " << (simetris ? "YAA" : "TIDAKK") << endl <<endl;
    system ("pause");
    
    cout << "Untuk semua a, b, c termasuk anggota himpunan A," << endl 
		 << "relasi R pada himpunan A disebut menghantar " << endl
		 << "jika (a, b) temasuk anggota relasi R" << endl
		 << "dan (b, c) termasuk anggota relasi R," << endl 
		 << "maka (a, c) termasuk anggota relasi R.\n";
    cout << "Transitif: " << (transitif ? "YAA" : "TIDAKK") << endl << endl;
    system ("pause");
    
    //=== Cek relasi ekuivalen (setara) ===
    cout << "=== Cek relasi ekuivalen (setara) ===\n";
    cout << "Suatu relasi P pada suatu himpunan S disebut relasi setara \n";
	cout << "atau relasi ekivalen (equivalence relation) pada himpunan S \n";
	cout << "apabila P bersifat refleksif, simetris dan transitif. \n";
	system ("pause");

    if (refleksif && simetris && transitif) {
        cout << "\nRelasi ini merupakan relasi EKUIVALEN (SETARA).\n";
    }
    else cout << "Relasi ini bukan relasi EKUIVALEN (SETARA).\n";


    return 0;
}
