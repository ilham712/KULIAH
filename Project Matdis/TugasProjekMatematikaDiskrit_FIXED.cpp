#include <iostream>
#include <string>
using namespace std;

int main() {
    string himpunan[10][50]; // deklarasi tipe data string himpunan [h][i], berarti ada himpunan maks 10 dengan elemen tiap himpunan nya maks 50
    string namaHimpunan[10]; // nama-nama himpunan (A, B, C, dst), pembatasannya hanya sampe 10 karena himpunannya jg maks 10 aja
    int jumlahHimpunan;      // jumlah himpunan yang ingin dimasukkan
    int jumlahElemen[10];    // jumlah elemen untuk setiap himpunan

    while (true) { // looping agar program bisa diulang tanpa batas
        cout << "=== PROGRAM RELASI TERURUT (POSET) ===" << endl;

        // ==============================
        // INPUT JUMLAH HIMPUNAN
        // ==============================
        cout << "Masukkan jumlah himpunan: ";
        cin >> jumlahHimpunan;

        if (cin.fail() || jumlahHimpunan <= 0 || jumlahHimpunan > 10) {	//validitas kalau user input bukan angka atau bukan 1-10 
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Input tidak valid! Masukkan angka antara 1–10.\n\n";
            continue; //kmbali ke awal while tru loop
        }

        // ==============================
        // INPUT ELEMEN-ELEMEN SETIAP HIMPUNAN
        // ==============================
        for (int h = 0; h < jumlahHimpunan; h++) { //looping untuk input elemen untuk himpunan ke-h
            char nama = 'A' + h; // otomatis beri nama A, B, C, dst
            namaHimpunan[h] = nama; 

            cout << "\nMasukkan jumlah elemen himpunan " << namaHimpunan[h] << ": ";
            cin >> jumlahElemen[h];

            if (cin.fail() || jumlahElemen[h] <= 0 || jumlahElemen[h] > 50) {	//validasi kalau elemen itu harus 1-50
                cin.clear(); //membersihkan status error di input stream (biar bisa menerima input baru).
                cin.ignore(1000, '\n'); //membuang sisa input yang salah dari buffer (misal huruf, spasi, atau enter yang masih nyangkut)
                cout << "Input tidak valid! Masukkan angka antara 1–50.\n";
                h--; //Kurangi h supaya iterasi for mengulang himpunan yang sama lagi — artinya user diminta menginput jumlah elemen untuk himpunan yang sama ulang.
                continue;
            }

            cout << "Masukkan elemen-elemen himpunan " << namaHimpunan[h] << ":\n";
            for (int i = 0; i < jumlahElemen[h]; i++) { //looping untuk masukkan elemen
                cout << "Elemen ke-" << i + 1 << ": "; //Prompt untuk setiap elemen; ditampilkan urutan ke-1, ke-2, dst. (i+1 agar manusiawi, karena array index dimulai 0).
                cin >> himpunan[h][i]; //Baca input elemen sebagai string dan simpan di array himpunan[h][i].
            }
        }

        // ==============================
        // PILIH RELASI DARI HIMPUNAN MANA KE MANA
        // ==============================
        int idxAsal = 0, idxTujuan = 0; //Dua variabel untuk menyimpan pilihan nomor himpunan asal dan tujuan (nomor 1..n, nanti dikurangi 1 untuk index).

        if (jumlahHimpunan > 1) {
            cout << "\nPilih relasi dari himpunan mana ke himpunan mana:\n";
            for (int h = 0; h < jumlahHimpunan; h++) {
                cout << h + 1 << ". Himpunan " << namaHimpunan[h] << " = { ";
                for (int i = 0; i < jumlahElemen[h]; i++) {
                    cout << himpunan[h][i];
                    if (i != jumlahElemen[h] - 1) cout << ", ";
                }
                cout << " }" << endl;
            }

            cout << "Masukkan nomor himpunan asal (domain)  : ";
            cin >> idxAsal;
            cout << "Masukkan nomor himpunan tujuan (kodomain): ";
            cin >> idxTujuan;

            if (idxAsal < 1 || idxAsal > jumlahHimpunan || idxTujuan < 1 || idxTujuan > jumlahHimpunan) {
                cout << "Nomor himpunan tidak valid!\n\n";
                continue;
            }

            idxAsal--;
            idxTujuan--;
        } else {
            cout << "\nKarena hanya ada satu himpunan, relasi otomatis dari A ke A.\n";
        }

        // ==============================
        // PILIH JENIS RELASI (TOTAL / SEBAGIAN)
        // ==============================
        string relasiA[100], relasiB[100];
        int jumlahRelasi = 0;
        int jenis;

        cout << "\nPilih jenis relasi:\n";
        cout << "1. Terurut lengkap (semua pasangan dibandingkan)\n";
        cout << "2. Terurut tidak lengkap (masukkan relasi manual)\n";
        cout << "Pilihan (1/2): ";
        cin >> jenis;

        if (jenis == 1) {
            cout << "\nRelasi Terurut Lengkap (Universal):\nR = { ";
            for (int i = 0; i < jumlahElemen[idxAsal]; i++) {
                for (int j = 0; j < jumlahElemen[idxTujuan]; j++) {
                    relasiA[jumlahRelasi] = himpunan[idxAsal][i];
                    relasiB[jumlahRelasi] = himpunan[idxTujuan][j];
                    jumlahRelasi++;
                    cout << "(" << himpunan[idxAsal][i] << "," << himpunan[idxTujuan][j] << ")";
                    if (!(i == jumlahElemen[idxAsal] - 1 && j == jumlahElemen[idxTujuan] - 1))
                        cout << ", ";
                }
            }
            cout << " }\n";
        } else if (jenis == 2) {
            cout << "\nRelasi Terurut Tidak Lengkap (input manual):\n";
            cout << "Masukkan pasangan relasi (contoh: a b). Ketik 'selesai' untuk berhenti.\n";
            while (true) {
                string a, b;
                cout << "Pasangan: ";
                cin >> a;
                if (a == "selesai") break;
                cin >> b;
                relasiA[jumlahRelasi] = a;
                relasiB[jumlahRelasi] = b;
                jumlahRelasi++;
            }

            cout << "\nRelasi yang terbentuk R = { ";
            for (int i = 0; i < jumlahRelasi; i++) {
                cout << "(" << relasiA[i] << "," << relasiB[i] << ")";
                if (i != jumlahRelasi - 1) cout << ", ";
            }
            cout << " }\n";
        } else {
            cout << "Pilihan tidak valid.\n";
            continue;
        }

        // ==============================
        // TANYA APAKAH MAU CEK SIFAT RELASI
        // ==============================
        char mauCek;
        cout << "\nApakah ingin mengecek sifat relasi (refleksif, antisimetris, transitif)? (y/n): ";
        cin >> mauCek;

        if (mauCek == 'y' || mauCek == 'Y') {

            bool refleksif = false, antisimetris = false, transitif = false;
            string alasanR, alasanA, alasanT;
            char menu;

            while (true) {
                cout << "\n=== MENU PEMERIKSAAN SIFAT RELASI ===\n";
                cout << "1. Cek Refleksif\n";
                cout << "2. Cek Antisimetris\n";
                cout << "3. Cek Transitif\n";
                cout << "4. Lihat hasil keseluruhan\n";
                cout << "5. Kembali ke awal (ulang program)\n";
                cout << "6. Exit (keluar dari program)\n";
                cout << "Pilihan: ";
                cin >> menu;

                if (menu == '1') {
                    bool semuaAda = true; //asumsi awal bahwa semua elemen punya (a,a) makanya nilainya true
                    for (int i = 0; i < jumlahElemen[idxAsal]; i++) { //mengecek setiap elemen a dalam himpunan asal
                        bool ada = false; //untuk setiap elemen a, kita cari apakah (a,a) ada di dalam relasi
                        for (int j = 0; j < jumlahRelasi; j++) { //Loop semua pasangan relasi (relasiA[j], relasiB[j]).
                            if (relasiA[j] == himpunan[idxAsal][i] && relasiB[j] == himpunan[idxAsal][i])
                                ada = true; //Kalau ketemu pasangan (a,a), tandai ada = true.
                        }
                        if (!ada) semuaAda = false; //Kalau satu saja elemen a tidak punya pasangan (a,a), relasi bukan refleksif.
                    }
                    refleksif = semuaAda; //penyimpanan hasil
                    alasanR = refleksif ? "Setiap elemen memiliki pasangan (a,a)." : "Ada elemen yang tidak memiliki pasangan (a,a).";
                    cout << "Refleksif: " << (refleksif ? "Ya, " : "Tidak, ") << "karena " << alasanR << endl;
                } else if (menu == '2') {
                    bool aman = true; //asumsi awal bahwa semua elemen antisimetri
                    for (int i = 0; i < jumlahRelasi; i++) { //mengecek emua pasangan relasi (a,b) terhadap h(b,a)
                        for (int j = 0; j < jumlahRelasi; j++) {
                            if (relasiA[i] == relasiB[j] && relasiB[i] == relasiA[j] && relasiA[i] != relasiB[i]) {
                                aman = false;
                            }
                        }
                    }
                    antisimetris = aman;
                    alasanA = antisimetris ? "Tidak ada pasangan (a,b) dan (b,a) untuk a != b." :
                                             "Terdapat pasangan (a,b) dan (b,a) dengan a != b.";
                    cout << "Antisimetris: " << (antisimetris ? "Ya, " : "Tidak, ") << "karena " << alasanA << endl;
                } else if (menu == '3') {
                    bool transitifSemua = true;
                    for (int i = 0; i < jumlahRelasi; i++) {
                        for (int j = 0; j < jumlahRelasi; j++) {
                            if (relasiB[i] == relasiA[j]) {
                                bool ada = false;
                                for (int k = 0; k < jumlahRelasi; k++) {
                                    if (relasiA[k] == relasiA[i] && relasiB[k] == relasiB[j]) ada = true;
                                }
                                if (!ada) transitifSemua = false;
                            }
                        }
                    }
                    transitif = transitifSemua;
                    alasanT = transitif ? "Jika (a,b) dan (b,c) ada, maka (a,c) juga ada." :
                                          "Ada (a,b) dan (b,c) tapi (a,c) tidak ditemukan.";
                    cout << "Transitif: " << (transitif ? "Ya, " : "Tidak, ") << "karena " << alasanT << endl;
                } else if (menu == '4') {
                    cout << "\n=== HASIL AKHIR RELASI ===\n";
                    cout << "Refleksif    : " << (refleksif ? "Ya, " : "Tidak, ") << "karena " << alasanR << endl;
                    cout << "Antisimetris : " << (antisimetris ? "Ya, " : "Tidak, ") << "karena " << alasanA << endl;
                    cout << "Transitif    : " << (transitif ? "Ya, " : "Tidak, ") << "karena " << alasanT << endl;

                    if (refleksif && antisimetris && transitif) {
                        cout << "\nRelasi ini ADALAH relasi terurut (Poset)." << endl;
                        if (jenis == 1)
                            cout << "Karena semua elemen dapat dibandingkan, maka relasi ini disebut relasi TERURUT TOTAL.\n";
                        else
                            cout << "Karena tidak semua elemen dapat dibandingkan, maka relasi ini disebut relasi TERURUT SEBAGIAN.\n";
                    } else {
                        cout << "\nRelasi ini BUKAN relasi terurut (Poset).\n";
                    }
                } else if (menu == '5') {
                    break; // kembali ke awal program
                } else if (menu == '6') {
                    cout << "\nTerima kasih telah menggunakan Program Belajar Relasi Terurut.\n";
                    cout << "-Graviela, Naluri, Nayla\n";                    
                    return 0; // keluar dari seluruh program
                } else {
                    cout << "Pilihan tidak valid!\n";
                }

                cout << "\nTekan Enter untuk melanjutkan...";
                cin.ignore();
                cin.get();
            }
        }

        cout << "\n--------------------------------------------\n\n";
    }

    return 0;
}
