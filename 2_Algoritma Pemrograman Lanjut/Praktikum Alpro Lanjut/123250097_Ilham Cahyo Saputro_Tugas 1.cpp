#include <iostream>
#include <string>
using namespace std;

// Struct Sesi Latihan
struct SesiLatihan {
	int id;					// untuk ID sesi latihan
	string jenisLatihan; 	// untuk jenis latihan (Lari, Angkat Beban, dll)
	int durasi;         	// untuk durasi (menit)
    int kalori;         	// untuk kalori
};

// Variabel Global
const int MAX_SESI = 100; // Batas maksimal sesi
SesiLatihan SL[MAX_SESI];
int jumlahSesi = 0;

// Deklarasi Fungsi
void catatSesiWO();
void riwayatLatihan();
int hitungTotalKalori(SesiLatihan arr[], int n);
void cariSesiWO();
void urutkanBerdasarkanID(SesiLatihan arr[], int n);
void binarySearch(SesiLatihan arr[], int n, int cariID);


int main () {
	int pilihan;
	do {
		cout << "=======================================" << endl;
		cout << "| Log Catatan Kebugaran (Workout Log) | \n";
		cout << "=======================================" << endl;
		cout << "1. Catat Sesi Workout                 |\n";
		cout << "2. Riwayat Latihan                    |\n";
		cout << "3. Cari sesi                          |\n";
		cout << "4. Exit                               |\n";
		cout << "_______________________________________\n";
		cout << "Silakan Pilih Menu : "; cin >> pilihan;
		cout << endl;
	
		switch (pilihan) {
			case 1:
				catatSesiWO();
				break;
			case 2:
				riwayatLatihan();
				break;
			case 3:
				cariSesiWO();
				break;
			case 4:
				system("cls");
				cout << "Terima kasih telah menggunakan aplikasi Workout Log, sehat selalu yaa :) \n";
				break;
			default:
				system("cls");
				cout << "Pilihan Anda tidak valid, silakan pilih lagi! \n\n";
				break;
	}
	} while (pilihan != 4);
	
	return 0;
}

// Fungsi Catat Sesi WO
void catatSesiWO () {
	if (jumlahSesi >= MAX_SESI) {
		cout << "Jumlah Sesi WO Anda mencapai batas!!!\n\n";
		system("pause");
		system("cls");
		return;
	}
	
	cout << "--- Catat Sesi WO Baru---\n";
	cout << "ID Sesi : "; cin >> SL[jumlahSesi].id;
	
	cout << "Jenis Latihan (Lari, Angkat Beban, dll) : ";
    cin.ignore(); 
    getline(cin, SL[jumlahSesi].jenisLatihan);
    
    cout << "Durasi (menit): ";
    cin >> SL[jumlahSesi].durasi;
    
    cout << "Kalori Terbakar: ";
    cin >> SL[jumlahSesi].kalori;

    jumlahSesi++;
    cout << "\nYEAYYYY Sesi WO berhasil dicatat!\n" << endl;
    system("pause");
    system("cls");
}

// Fungsi Riwayat Latihan 
void riwayatLatihan() {
	cout << "\n --- Riwayat Latihan --- \n\n";
	if (jumlahSesi == 0) {
		cout << "Belum ada data latihan, Silakan input Sesi Latihan dulu\n\n";
		system("pause");
		system("cls");
		return;
	}
	
	for (int i = 0; i < jumlahSesi; i++) {
		cout << "Sesi Latihan ke-" << i + 1 << endl;
		cout << "ID Sesi		: " << SL[i].id << endl;
		cout << "Jenis Latihan	: " << SL[i].jenisLatihan << endl;
		cout << "Durasi		: " << SL[i].durasi << endl;
		cout << "Kalori		: " << SL[i].kalori << endl;
		cout << "___________________________________\n"; 
	}
	
	int total_kalori = hitungTotalKalori(SL, jumlahSesi); // pemanggilan fungsi hitung kalori
	cout << "\nTotal Kalori	: " << total_kalori << " Kalori\n\n"; 
	
	system("pause");
	system("cls");
}

// Fungsi untuk Menghitung Total Kalori dari semua sesi latihan
int hitungTotalKalori(SesiLatihan arr[], int n) {
    if (n <= 0) {
        return 0;
    }
    else {
		return arr[n - 1].kalori + hitungTotalKalori(arr, n - 1);
	}
}

// Fungsi untuk mencari Sesi Latihan berdasarkan ID sesi
void cariSesiWO() {
	cout << "\n --- Cari Sesi Latihan --- \n\n";
	if (jumlahSesi == 0) {
		cout << "Belum ada data sesi latihan, Silakan input Sesi Latihan dulu\n\n";
		system("pause");
		system("cls");
		return;
	}
	
	SesiLatihan SL_copy[MAX_SESI];
    for(int i = 0; i < jumlahSesi; i++) {
        SL_copy[i] = SL[i];
	}
	// Pemanggilan Fungsi urutkan data sebelum melakukan pencarian dengan binary search
	urutkanBerdasarkanID(SL_copy, jumlahSesi);
	
	int cariID;
	cout << "Silakan Masukkan ID Sesi yang dicari : ";
	cin >> cariID;
	
	binarySearch(SL_copy, jumlahSesi, cariID);
}

// Fungsi untuk mengurutkan data sesi latihan 
void urutkanBerdasarkanID(SesiLatihan arr[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = 1; j < n-i; j++) {
			if (arr[j-1].id > arr[j].id) {
				SesiLatihan temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

// Fungsi Untuk Mencari Data dengan menggunakan Binary Search
void binarySearch(SesiLatihan arr[], int n, int cariID) {
	bool found = false;
    int kiri = 0;
    int kanan = n - 1;
    int ketemu = -1;

    while (!found && (kiri <= kanan)) {
        int mid = kiri + (kanan - kiri) / 2;
        
        if (arr[mid].id == cariID) {
            found = 1;
            ketemu = mid;
        } else{
            if (cariID < arr[mid].id) {
                kanan = mid - 1;
            } else {
				kiri = mid + 1;
			}
        }
    }
    
     if(found) {
        cout << "\nSesi Ditemukan!\n";
        cout << "ID Sesi		: " << arr[ketemu].id << endl;
        cout << "Jenis Latihan	: " << arr[ketemu].jenisLatihan << endl;
        cout << "Durasi		: " << arr[ketemu].durasi << " menit" << endl;
        cout << "Kalori		: " << arr[ketemu].kalori << endl; 
    } else {
        cout << "\nSesi dengan ID " << cariID <<  " Tidak Ditemukan\n";
    }
    
    system("pause");
    system("cls");
}

