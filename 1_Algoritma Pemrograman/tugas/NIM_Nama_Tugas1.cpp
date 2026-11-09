#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// ==========================================
// 1. DEFINISI STRUCT
// ==========================================
struct SesiLatihan {
    int id;             // ID Sesi
    string jenis;       // Jenis Latihan (Lari, Angkat Beban, dll)
    int durasi;         // Durasi (menit)
    int kalori;         // Kalori Terbakar
};

// ==========================================
// 2. VARIABEL GLOBAL
// ==========================================
const int MAX_SESI = 100; // Batas maksimal sesi
SesiLatihan sesiList[MAX_SESI];
int jumlahSesi = 0;

// ==========================================
// 3. FUNGSI REKURSIF (Hitung Total Kalori)
// ==========================================
// Ketentuan: Menggunakan teknik divide and conquer atau pemanggilan rekursif mundur
// Implementasi di sini menggunakan Pemanggilan Rekursif Mundur (Backward Recursion)
int hitungTotalKalori(SesiLatihan arr[], int n) {
    // Base Case: Jika tidak ada sesi (n <= 0), return 0
    if (n <= 0) {
        return 0;
    }
    // Recursive Step: Kalori sesi terakhir + hasil rekursif sisa sesi sebelumnya
    return arr[n - 1].kalori + hitungTotalKalori(arr, n - 1);
}

// ==========================================
// 4. FUNGSI SORTING (Syarat Binary Search)
// ==========================================
// Binary Search mengharuskan data terurut berdasarkan ID
void urutkanBerdasarkanID() {
    // Menggunakan Bubble Sort sederhana untuk mengurutkan array of struct
    for (int i = 0; i < jumlahSesi - 1; i++) {
        for (int j = 0; j < jumlahSesi - i - 1; j++) {
            if (sesiList[j].id > sesiList[j + 1].id) {
                // Tukar posisi jika ID sebelumnya lebih besar
                SesiLatihan temp = sesiList[j];
                sesiList[j] = sesiList[j + 1];
                sesiList[j + 1] = temp;
            }
        }
    }
}

// ==========================================
// 5. FUNGSI BINARY SEARCH
// ==========================================
int binarySearch(int targetID) {
    int left = 0;
    int right = jumlahSesi - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Cek apakah ID di tengah adalah target
        if (sesiList[mid].id == targetID) {
            return mid;
        }

        // Jika target lebih besar, abaikan setengah kiri
        if (sesiList[mid].id < targetID) {
            left = mid + 1;
        } 
        // Jika target lebih kecil, abaikan setengah kanan
        else {
            right = mid - 1;
        }
    }
    return -1; // Data tidak ditemukan
}

// ==========================================
// 6. FUNGSI MENU & FITUR
// ==========================================

// Menu 1: Catat Sesi Workout
void catatSesi() {
    if (jumlahSesi >= MAX_SESI) {
        cout << "\n[!] Penyimpanan penuh!" << endl;
        return;
    }

    cout << "\n--- Catat Sesi Workout Baru ---" << endl;
    cout << "ID Sesi: ";
    cin >> sesiList[jumlahSesi].id;
    
    cout << "Jenis Latihan (contoh: Lari, Angkat Beban): ";
    cin.ignore(); // Membersihkan buffer newline sebelum getline
    getline(cin, sesiList[jumlahSesi].jenis);
    
    cout << "Durasi (menit): ";
    cin >> sesiList[jumlahSesi].durasi;
    
    cout << "Kalori Terbakar: ";
    cin >> sesiList[jumlahSesi].kalori;

    jumlahSesi++;
    cout << "[OK] Sesi berhasil dicatat!" << endl;
}

// Menu 2: Riwayat Latihan (Memanggil Fungsi Rekursif)
void tampilkanRiwayat() {
    cout << "\n--- Riwayat Latihan ---" << endl;
    if (jumlahSesi == 0) {
        cout << "Belum ada data latihan." << endl;
        return;
    }

    // Header Tabel
    cout << left << setw(10) << "ID" 
         << setw(20) << "Jenis" 
         << setw(10) << "Durasi" 
         << setw(10) << "Kalori" << endl;
    cout << "------------------------------------------------------------" << endl;

    // Tampilkan semua data
    for (int i = 0; i < jumlahSesi; i++) {
        cout << left << setw(10) << sesiList[i].id
             << setw(20) << sesiList[i].jenis
             << setw(10) << sesiList[i].durasi
             << setw(10) << sesiList[i].kalori << endl;
    }

    cout << "------------------------------------------------------------" << endl;
    
    // Panggil fungsi rekursif sesuai ketentuan tugas
    int total = hitungTotalKalori(sesiList, jumlahSesi);
    cout << "Total Kalori Terbakar (Via Rekursif): " << total << " kalori" << endl;
}

// Menu 3: Cari Sesi (Menggunakan Binary Search)
void cariSesi() {
    cout << "\n--- Cari Sesi Berdasarkan ID ---" << endl;
    if (jumlahSesi == 0) {
        cout << "Belum ada data untuk dicari." << endl;
        return;
    }

    // Ketentuan: Pastikan data diurutkan berdasarkan ID terlebih dahulu
    urutkanBerdasarkanID();
    cout << "(Info: Data telah diurutkan berdasarkan ID untuk memenuhi syarat Binary Search)" << endl;

    int targetID;
    cout << "Masukkan ID Sesi yang dicari: ";
    cin >> targetID;

    int index = binarySearch(targetID);

    if (index != -1) {
        cout << "\n[OK] Sesi Ditemukan!" << endl;
        cout << "ID      : " << sesiList[index].id << endl;
        cout << "Jenis   : " << sesiList[index].jenis << endl;
        cout << "Durasi  : " << sesiList[index].durasi << " menit" << endl;
        cout << "Kalori  : " << sesiList[index].kalori << endl;
    } else {
        cout << "\n[!] Sesi dengan ID " << targetID << " tidak ditemukan." << endl;
    }
}

// ==========================================
// 7. MAIN PROGRAM
// ==========================================
int main() {
    int pilihan;
    do {
        cout << "\n========================================" << endl;
        cout << "   Log Catatan Kebugaran (Workout Log)  " << endl;
        cout << "========================================" << endl;
        cout << "1. Catat Sesi Workout" << endl;
        cout << "2. Riwayat Latihan" << endl;
        cout << "3. Cari Sesi" << endl;
        cout << "4. Exit" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                catatSesi();
                break;
            case 2:
                tampilkanRiwayat();
                break;
            case 3:
                cariSesi();
                break;
            case 4:
                cout << "Terima kasih telah menggunakan aplikasi." << endl;
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi." << endl;
        }
    } while (pilihan != 4);

    return 0;
}
