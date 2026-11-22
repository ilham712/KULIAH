#include <iostream>
using namespace std;

int main () {
	int film;
	int umur;
	int tambahan= 0;
	int hari;
	int harga = 0;
	double diskon = 0;
	
	cout << "Selamat datang di pemesanan tiket bioskop\n";
	cout << "1. Action (Rp. 50.000)\n";
	cout << "2. Drama (Rp. 40.000)\n";
	cout << "3. Animasi ( Rp. 35.000)\n";
	cout << "Masukkan pilihan anda: ";
	cin >> film;
	
	switch (film){
	case 1:
		harga = 50000;
	break;
	case 2:
		harga = 40000;
	break;
	case 3:
		harga = 35000;
	break;
	default:
		cout << "Tidak ada pilihan" << endl;
	}
	
	cout << "Anak-anak (12 tahun kebawah) diskon 50% \n";
	cout << "Remaja (12-18) diskon 20% \n";
	cout << "Dewasa (diatas 18 tahun) tidak ada diskon \n";
	cout << "Masukkan Umur penonton: ";
	cin >> umur;
	
	if (umur < 12) {
		diskon = 0.5;
	}else if (umur >= 12 && umur <= 18){
		diskon = 0.2;
	}else if ( umur > 18) {
		diskon = 0.0;
	}else {
		cout << "Umur yang anda masukkan tidak sesuai kriteria\n";
	}
	
	cout << "Hari pemesanan: \n";
	cout << "1. Senin\n";
	cout << "2. Selasa\n";
	cout << "3. Rabu\n";
	cout << "4. Kamis\n";
	cout << "5. Jumat\n";
	cout << "6. Sabtu\n";
	cout << "7. Minggu\n";
	cout << "Masukkan hari: ";
	cin >> hari;
	
	if (hari >= 1 && hari <=4){
		tambahan = 0;
	} else if (hari >= 5 && hari <=7){
		tambahan = 5000;
	} else {
		cout << "Hari yang dipilih tidak valid";
	}
	
	double potongan = harga*diskon;
	int hargaTotal = (harga - potongan) + tambahan;
	cout << "Total bayar: " << hargaTotal;
	
	return 0;
}

