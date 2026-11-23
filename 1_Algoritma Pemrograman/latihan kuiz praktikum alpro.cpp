#include <iostream>
using namespace std;

int main () {
	
	int pilih, pilihMakanan, pilihMinuman, pilihCekHarga, pilihOpsiDiskon;
	bool exit = false;
	int totalHarga = 0;
	string kodePromo = "MUYPJ";
	string inputPromo;
	int uangBayar;
	
	do{
		cout << "=== Kantin Sekolah Digital ===\n";
		cout << "1. Makanan\n";
		cout << "2. Minuman\n";
		cout << "3. Cek Harga\n";
		cout << "4. Keluar\n";
		cout << "Pilih: "; cin >> pilih;
		
		switch(pilih){
			case 1 :
				system("cls");
				cout << "=== Daftar Makanan ===\n";
				cout << "1. Nasi Goreng (Rp. 12.000)\n";
				cout << "2. Mie Ayam Afui (Rp. 10.000)\n";
				cout << "3. Roti Bakar (Rp. 15.000)\n";
				cout << "Pilih makanan Anda: "; cin >> pilihMakanan;
				cout << endl;
				
				if (pilihMakanan == 1){
					totalHarga = totalHarga + 12000;
				} else if (pilihMakanan == 2){
					totalHarga = totalHarga + 10000;
				} else if (pilihMakanan == 3){
					totalHarga = totalHarga + 15000;
				} else {
					cout << "Menu makanan yang Anda pilih tidak tersedia\n";
				}
				system("cls");
				break;
			case 2 :
				system("cls");
				cout << "=== Daftar Minuman ===\n";
				cout << "1. Es Teh (Rp. 3.000)\n";
				cout << "2. Es Jeruk (Rp. 5.000)\n";
				cout << "3. Susu Cokelat (Rp. 7.000)\n";
				cout << "Pilih minuman Anda: "; cin >> pilihMinuman;
				cout << endl;
				
				if (pilihMinuman == 1){
					totalHarga = totalHarga + 3000;
				} else if (pilihMinuman == 2){
					totalHarga = totalHarga + 5000;
				} else if (pilihMinuman == 3){
					totalHarga = totalHarga + 7000;
				} else {
					cout << "Menu minuman yang Anda pilih tidak tersedia\n";
				}
				system("cls");
				break;
			case 3 :
				cout << "Total harga pembelian Anda saat ini adalah Rp. " << totalHarga << endl;
				
				if (totalHarga > 10000){
					cout << "Anda berhak memasukkan kode promo\n";
					cout << "Kode Promo: "; cin >> inputPromo;
					cout << endl;
					
					if (inputPromo == kodePromo){
						system("cls");
						cout << "SELAMAT!! Anda mendapatkan diskon 10% \n";
						cout << "Total Harga sebelum : Rp. " << totalHarga << endl;
						totalHarga = totalHarga - (totalHarga * 0.1);
						cout << "Total Harga sesudah : Rp. " << totalHarga << endl << endl;
					} else {
						system("cls");
						cout << "Kode Promo Anda salah\n";
						cout << "1. Masukkan kode promo lagi\n";
						cout << "2. Lanjut Opsi Pembayaran\n";
						cout << "Pilih Opsi: "; cin >> pilihOpsiDiskon;
						
						if (pilihOpsiDiskon == 1){
							
							while (inputPromo != kodePromo){
								cout << "Kode Promo: "; cin >> inputPromo;
								
								if (inputPromo == kodePromo){
									system("cls");
									cout << "SELAMAT!! Anda mendapatkan diskon 10% \n";
									cout << "Total Harga sebelum : Rp. " << totalHarga << endl;
									totalHarga = totalHarga - (totalHarga * 0.1);
									cout << "Total Harga sesudah : Rp. " << totalHarga << endl << endl;
								} else {
									system("cls");
									cout << "Kode Promo Anda salah\n";
									cout << "1. Masukkan kode promo lagi\n";
									cout << "2. Lanjut Opsi Pembayaran\n";
									cout << "Pilih Opsi: "; cin >> pilihOpsiDiskon;
									
									if (pilihOpsiDiskon == 2){
										system("cls");
										break;
									}
								}
							}
						} else if (pilihOpsiDiskon == 2){
							system("cls");
							cout << "......\n";
						}
					}
					
				} else{
					system("cls");
					cout << "......\n";
				}
				cout << "Total harga pembelian yang harus Anda bayar adalah Rp. " << totalHarga << endl;
				cout << "=== Opsi Pembayaran ===\n";
				cout << "1. Bayar\n";
				cout << "2. Hapus Pesanan\n";
				cout << "3. Kembali\n";
				cout << "Pilih Opsi Pembayaran Anda: "; cin >> pilihCekHarga;
				
					if (pilihCekHarga == 1){
						cout << "Masukkan jumlah uang Anda: "; cin >> uangBayar;
						if (totalHarga == uangBayar){
							cout << "Uang Anda pas...\n";
							cout << "Terimakasih telah membeli di kantin sekolah digital, semoga harimu minggu selalu ><\n\n";
						} else if (totalHarga > uangBayar){
							cout << "Uang Anda tidak cukup, silakan membayar lagi\n";
							cout << "Kurang Rp. " << totalHarga - uangBayar << endl;
							cout << "Masukkan kekurangan uang Anda (harus sesuai kekurangannya) : "; cin >> uangBayar;
							cout << "Terimakasih telah membeli di kantin sekolah digital, semoga harimu minggu selalu ><\n\n";
						} else if (totalHarga < uangBayar){
							cout << "Kembalian Anda: Rp. " << uangBayar - totalHarga << endl;
							cout << "Terimakasih telah membeli di kantin sekolah digital, semoga harimu minggu selalu ><\n\n";
						}
						totalHarga = totalHarga * 0;
					} else if (pilihCekHarga == 2){
						cout << "Pesanan Anda telah dihapus\n\n";
						totalHarga = totalHarga * 0;
					} else if (pilihCekHarga == 3){
						cout << "Kembali ke menu utama\n\n";
					}
				break;
			case 4 :
				system("cls");
				exit = true;
				break;
			default :
				system("cls");
				cout << "Menu tidak tersedia!!\n";
		}
		
		
	}while (exit == false);
	return 0;
}
