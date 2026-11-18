#include <iostream>
using namespace std;

int main () {
	int harga;
	int uang, kembalian;
	int menu;
	
	cout << "Selamat datang\n";
	cout << "1. Nasi Goreng\n";
	cout << "2. Ayam Goreng\n";
	cout << "3. Es Teh\n";
	cout << "4. Es Jeruk\n";
	cout << "Masukkan pilihan anda:\n";
	cin >> menu;
	
	switch (menu){
	case 1:
		cout << "Harga Nasi Goreng: Rp.10000\n";
		harga = 10000;
	break;
	case 2:
		cout << "Harga Ayam Goreng: Rp.12000\n";
		harga = 12000;
	break;
	case 3:
		cout << "Harga Es Teh: Rp.3000\n";
		harga = 3000;
	break;
	case 4:
		cout << "Harga Es Jeruk: Rp.3000\n";
		harga = 3000;
	break;
		default:
		cout << "Tidak ada pilihan";
	}
	
	cout << "Monggo bayar dulu: ";
	cin >> uang;
	
	if(uang < harga) {
		cout << "mau beli ayam apa permen mas";
	}else if(uang == harga){
		cout << "terimakasih";
	}else {
		kembalian = uang - harga;
		cout << "kembalian....." << kembalian << endl;
	}

}
