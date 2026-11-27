#include <iostream>
using namespace std;

const int jumlah_mahasiswa = 4;

int nilaiTugas23[jumlah_mahasiswa][2]={
        {80, 80},
        {65, 65},
        {85, 85},
        {65, 65}
    };
    
float cariRataRata(int kolom);
int cariTertinggi(int kolom);
int cariTerendah(int kolom);

int main () {
	float rata_rata[2];
	int tertinggi[2];
	int terendah[2]; 
	
	
	for (int k = 0; k < 2; k++) {
		rata_rata[k] = cariRataRata(k);
		tertinggi[k] = cariTertinggi(k);
		terendah[k] = cariTerendah(k);
		cout << "TUGAS " << k + 2 << endl;
		cout << "Rata-Rata: "  << rata_rata[k] << endl;
		cout << "Tertinggi: " << tertinggi[k] << endl;
		cout << "Terendah: " << terendah[k] << endl << endl;
	}
}
float cariRataRata(int kolom) {
	float total = 0;
	float rata2;
    for (int i = 0; i < jumlah_mahasiswa; i++) {
        total += nilaiTugas23[i][kolom];
    }
    rata2 = total / jumlah_mahasiswa;
    
    return rata2;
    
}
int cariTertinggi(int kolom) {
	int tinggi = nilaiTugas23[0][kolom];
	for (int i = 1; i < jumlah_mahasiswa; i++) {
		if (nilaiTugas23[i][kolom] > tinggi) {
			tinggi = nilaiTugas23[i][kolom];
		}
	}
	return tinggi;
}

int cariTerendah(int kolom) {
	int rendah = nilaiTugas23[0][kolom];
	for (int i = 1; i < jumlah_mahasiswa; i++) {
		if (nilaiTugas23[i][kolom] < rendah) {
			rendah = nilaiTugas23[i][kolom];
		}
	}
	return rendah;
}
