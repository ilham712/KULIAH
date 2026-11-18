#include <iostream>
using namespace std;

double cari_rata2 (double, int);

int main () {
	int nilai[5];
	string namaMahasiswa[5];
	int jumlah;
	double totalNilai = 0;
	double rerata;
	int tertinggi, terendah;
	string raihTinggi;
	string raihRendah;
	
	
	cout << "===Program Pengolahan Nilai===\n\n";
	do {
		cout << "Masukkan jumlah mahasiswa: ";
		cin >> jumlah;
		if (jumlah > 5) {
			cout << "Jumlah mahasiswa melebihi batas\n";
		}
	} while(jumlah > 5);
	cout << endl;
	
	for (int i = 0; i < jumlah; i++){
		cout << "Input Nama Mahasiswa ke- " << i+1 << " : "; cin >> namaMahasiswa[i]; 
		cout << "Input Nilai Mahasiswa ke- " << i+1 << " : "; cin >> nilai[i]; 
		cout << endl;
	}
	
	cout << "=====================\n";
	cout << "---Hasil Pengolahan Data---\n\n";
	cout << "Daftar Nilai Mahasiswa: \n";
	
	for (int i = 0; i < jumlah; i++){
		cout << i+1 << "." << namaMahasiswa[i] << " : " << nilai[i];  
		cout << endl;
	}
	
	cout << endl;
	cout << "Statistik Nilai: \n";
	
	for (int i = 0; i < jumlah; i++){
		totalNilai = totalNilai + nilai[i];
	}
	rerata = cari_rata2 (totalNilai, jumlah);
	cout << "Nilai Rata-Rata: " << rerata << endl;
	
	// Nilai tertinggi
	tertinggi = nilai[0];
	raihTinggi = namaMahasiswa[0];
	for (int i = 0; i < jumlah; i++){
		if (nilai[i] > tertinggi) {
			tertinggi = nilai[i];
			raihTinggi = namaMahasiswa[i];
		}
	}
	cout << "Nilai Tertinggi: " << tertinggi << " (Diraih oleh: "<< raihTinggi  << ")" << endl;
	
	// Nilai terendah
	terendah = nilai[0];
	raihRendah = namaMahasiswa[0];
	for (int i = 0; i < jumlah; i++){
		if (nilai[i] < terendah) {
			terendah = nilai[i];
			raihRendah = namaMahasiswa[i];
		}
	}
	cout << "Nilai Terendah: " << terendah << " (Diraih oleh: "<< raihRendah  << ")" << endl;
	
	return 0;
}

double cari_rata2 (double tNilai, int jml) {
	double rata2;
	rata2 = tNilai / jml;
	
	return rata2;
}

