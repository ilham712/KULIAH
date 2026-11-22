#include <iostream>
using namespace std;

int main () {
	int pilih, pMakanan, pMinuman, pCekHarga;
	bool exit = false;
	int totalHarga;
	string promoCode = "MUYPJ";
	string inputPromo;
	
	do {
	cout << "=== Kantin Sekolah Digital ===\n";
	cout << "1. Makanan\n 2. Minuman\n 3. Cek Harga\n 4. Keluar\n";
	cout << "Pilih: "; cin >> pilih;
	
	switch (pilih){
		case 1:
			if (pMakanan)
		break;
		case 2:
		break;
		case 3:
		break;
		case 4:
			exit = true;
		break;
		default:
			system ("cls");
	}
	}while (exit = false);
}
