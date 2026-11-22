#include <iostream>
using namespace std;

int main () {
	int kg, jumlahMangga, t1, t2, t3, kebutuhan;
	
	cout << "Masukkan jumlah mangga yang dibeli (kg): "; cin >> kg;
	jumlahMangga = 2 * kg;
	
	cout << "Masukkan jumlah anggota keluarga tetangga 1: "; cin >> t1;
	cout << "Masukkan jumlah anggota keluarga tetangga 2: "; cin >> t2;
	cout << "Masukkan jumlah anggota keluarga tetangga 3: "; cin >> t3;
	kebutuhan = t1 + t2 + t3;
	
	cout << "\n=== Hasil Pembagian Mangga ===\n";
	if (jumlahMangga > kebutuhan){
		cout << "Sisa mangga: " << jumlahMangga - kebutuhan << " buah\n";
	} 
	else if (jumlahMangga == kebutuhan) {
		cout << "Tidak ada sisa mangga\n";
	}
	else {
		cout << "Mangga yang dibeli kurang";
	}
	return 0;
}
