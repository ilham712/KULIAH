#include <iostream>
using namespace std;

void menuUtama();
void tampilkanTiket();
void pembelianTiket();
void lihatPesanan();
long hitung_kembalian(long total, long bayar);


const string username = "algo";
const string password = "asyik";
const string voucher = "MUYPJ";
const int maksTransaksi = 100;
const int jumlahKategori = 2;

int jumlahTransaksi = 0;

string namaTiket[jumlahKategori] = {"VIP", "Festival"};
long NIK[maksTransaksi];
string nama[maksTransaksi];
int pilihKategori;
long hargaTiket[jumlahKategori] = {100000, 50000};
int jumlahTiket[maksTransaksi];
string inputVoucher;
char ulangKodepromo;
long total[maksTransaksi], bayar[maksTransaksi], kembalian[maksTransaksi];

int main () {
	string inputUser, inputPass;
	char ulangLogin;
	bool keluar = false;
	
	do {
		
		cout << "=== Sistem Kasir Konser ===\n";
		
		cout << "Masukkan username : "; cin >> inputUser;
		cout << "Masukkan password : "; cin >> inputPass;
	
		if (inputUser == username && inputPass == password) {
			cout << "Login berhasil\n";
			system("pause");
			system("cls");
			menuUtama();
			break;
		} else {
			cout << "\nUsername atau Password Anda salah\n";
			cout << "Apakah Anda ingin login ulang? (y/n): ";
			cin >> ulangLogin;
		
			if (ulangLogin == 'n' || ulangLogin == 'N') {
				cout << "\nAnda telah keluar dari program\n";
				keluar = true;
			}
		}
	} while (keluar == false);
	
	return 0;
} 

void menuUtama() {
	int pilih;
	do {
		cout << "===Menu Utama===\n";
		cout << "1. Tampilkan Tiket\n";
		cout << "2. Pembelian Tiket\n";
		cout << "3. Lihat Pesanan\n";
		cout << "4. Exit\n";
		cout << "Pilih Menu: ";
		cin >> pilih;
		
		switch (pilih) {
			case 1:
				tampilkanTiket();
				break;
			case 2:
				pembelianTiket();
				break;
			case 3:
				lihatPesanan();
				break;
			case 4:
				cout << "\nLogout Berhasil\n";
				break;
			default:
				system("cls");
				cout << "Pilihan Anda tidak tersedia. Silakan coba lagi\n";
		}
	} while (pilih != 4);
	
}

void tampilkanTiket() {
	system("cls");
	char kembali;
	
	do {
		cout << "=== Daftar Tiket ===\n";
		cout << "Kategori Tiket [1]\n";
		cout << "Jenis tiket	: VIP\n";
		cout << "Harga tiket	: 100.000\n\n";
		cout << "Kategori Tiket [2]\n";
		cout << "Jenis tiket	: Festival\n";
		cout << "Harga tiket	: 50.000\n\n";
		cout << "Kembali ke Menu Utama? [y] or [n] : ";
		cin >> kembali;
		
		if (kembali == 'y' || kembali == 'Y') {
			system("cls");
			break;
		} else {
			system("cls");
		}
	} while (true);

}

void pembelianTiket() {
	cout << "Kategori Tiket [1]\n";
	cout << "Jenis tiket	: VIP\n";
	cout << "Harga tiket	: 100.000\n\n";
	cout << "Kategori Tiket [2]\n";
	cout << "Jenis tiket	: Festival\n";
	cout << "Harga tiket	: 50.000\n\n";
	cout << "Pembelian Tiket\n\n";
	
	cout << "Silakan input NIK dan Nama Anda\n";
	cout << "NIK buyer		: ";
	cin >> NIK[jumlahTransaksi];
	cout << "Nama Buyer		: ";
	cin.ignore();
	getline(cin, nama[jumlahTransaksi]);
	
	do {
		cout << "Nomor Kategori Tiket	: ";
		cin >> pilihKategori;
		
		if (pilihKategori == 1) {
			cout << "Harga			: " << hargaTiket[0] << endl;
			cout << "Jenis Tiket		: " << namaTiket[0] << endl;
			cout << "Jumlah Tiket		: ";
			cin >> jumlahTiket[jumlahTransaksi];
			total[jumlahTransaksi] = jumlahTiket[jumlahTransaksi] * hargaTiket[0];
			cout << "Total			: " << total[jumlahTransaksi] << endl;
		} else if (pilihKategori == 2) {
			cout << "Harga			: " << hargaTiket[1] << endl;
			cout << "Jenis Tiket		: " << namaTiket[1] << endl;
			cout << "Jumlah Tiket 		: ";
			cin >> jumlahTiket[jumlahTransaksi];
			total[jumlahTransaksi] = jumlahTiket[jumlahTransaksi] * hargaTiket[1];
			cout << "Total			: " << total[jumlahTransaksi] << endl;
		} else {
			cout << "Pilihan Anda tidak tersedia, Kategori hanya tersedia 1-2\n";
		}
	} while (pilihKategori < 1 || pilihKategori > 2);
	
	do {
		cout << "Input Voucher (Jika tidak ada isi [t]) : ";
		cin >> inputVoucher;
		
		if (inputVoucher == voucher) {
			cout << "Selamat Anda mendapatkan diskon 10%\n";
			total[jumlahTransaksi] = total[jumlahTransaksi] - (total[jumlahTransaksi] * 0.1);
			cout << "Total setelah diskon	: " << total[jumlahTransaksi] << endl;
			break;
		} else if (inputVoucher == "t" || inputVoucher == "T") {
			cout << "Anda tanpa Voucher\n";
			break;
		} else {
			cout << "Voucher Anda tidak valid, Cobalagi? (y/n) : ";
			cin >> ulangKodepromo;	
				if (ulangKodepromo == 'N' || ulangKodepromo == 'n') {
					cout << "Anda tanpa Voucher\n";
					break;
				}
		}
	} while (ulangKodepromo == 'y' || ulangKodepromo == 'Y');
	
	do{
		cout << "Total Bayar sekarang 	: " << total[jumlahTransaksi] << endl;
		cout << "Nominal Pembayaran 	: ";
		cin >> bayar[jumlahTransaksi];
		if (bayar[jumlahTransaksi] >= total[jumlahTransaksi]) {
			kembalian[jumlahTransaksi] = hitung_kembalian(total[jumlahTransaksi], bayar[jumlahTransaksi]);
			cout << "Kembalian		: " << kembalian[jumlahTransaksi] << endl;
		} else {
			cout<<"Maaf uang Anda kurang\n";
		}
	} while (bayar[jumlahTransaksi] < total[jumlahTransaksi]);
	
	jumlahTransaksi++;
	
	system ("pause");
	system ("cls");
}

void lihatPesanan(){
	char kembali;
	
	do {
		system("cls");
		if (jumlahTransaksi == 0) {
			cout << "Belum ada transaksi\n";
		} else {
			cout << "=== Pesanan Anda ===\n\n";
			for (int i =0; i < jumlahTransaksi; i++) {
				cout << "Pesanan ke- " << i+1 << endl;
				cout << "NIK			: " << NIK[i] << endl;
				cout << "Nama			: "<< nama[i] << endl;
				cout << "Jenis tiket 		: " << namaTiket[i] << endl;
				cout << "Harga Tiket 		: " << hargaTiket[i] << endl;
				cout << "Jumlah Tiket		: "<< jumlahTiket[i] << endl;
				cout << "Total			: " << total[i] << endl;
				cout << "Nominal Pembayaran	: " << bayar[i] << endl;
				cout << "Kembalian		: " << kembalian[i] << endl;
				cout << endl;
			}
		}
		cout << "Kembali ke Menu Utama? [y] or [n] : ";
		cin >> kembali;
		if (kembali == 'y' || kembali == 'Y') {
			system("cls");
			break;
		} else {
			system("cls");
		}
	} while (true);
	
	
}

long hitung_kembalian(long total, long bayar) {
	long kmbli;
	kmbli = bayar - total;
	
	return kmbli;
}
