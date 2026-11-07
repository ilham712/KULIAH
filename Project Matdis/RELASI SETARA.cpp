#include <iostream>
using namespace std;

int main () {
	// code untuk memasukkan jumlah anggota dan anggota himpunan asal
	int n; // n = jumlah anggota himpunan asal
	cout << "Masukkan jumlah anggota himpunan asal: ";
	cin >> n;
	int himp[n];
	
	for (int i=1; i<=n;i++) {
		cout << "Masukkan anggota himpunan asal ke-" << i << ":";
		cin >> himp[i];
	}
	cout << "Anggota himpunan asal= { ";
	for (int i=1;i<=n;i++) {
		cout << himp[i] << " ";
	}
	cout << "}\n\n";
	
	// code untuk memasukkan jumlah anggota dan anggota relasi himpunan
	 int m; // n = jumlah anggota himpunan relasi
	 cout << "Masukkan jumlah anggota himpunan relasi: "; 
	 cin >> m;
	 int relasi[m][2];
	 cout << "Format pengisian anggota himpunan relasi: 1 1\n";
	 for (int i=1; i<=m; i++) {
		cout << "Masukkan anggota himpunan relasi ke-" << i << ":";
		cin >> relasi[i][1] >> relasi[i][2];
	 }
	 cout << "Anggota himpunan relasi = {";
	 for (int i=1; i<=m; i++) {
		 cout << "(" << relasi[i][1] << "," << relasi[i][2] << ")" ;
	 }
	 cout << "}" << endl << endl;
	 
	 // code untuk cek sifat refleksif
	 bool refleksif= false;
	 for (int i=1; i<=m; i++) {
		 if (relasi[i][1]==relasi[i][2]) {
			 refleksif = true;
		 }
	 }
	 
	 // code untuk cek sifat simetris
	 bool simetris=false;
	 for (int i=1; i<=m;i++) {
		 for (int j=1;j<=m;j++) {
			 if (relasi[i][1]==relasi[j][2] && relasi[i][2]==relasi[j][1]) {
				 simetris = true;
				 continue;
			 }
			 else simetris=false;
		 }
	 }
	 
	 // code untuk menampilkan sifat-sifat dari hubungan antar himpunan di atas
	 cout << "Apakah refleksif? ";
	 if (refleksif) {
		cout << "Ya\n";
	} else {
		cout << "Tidak\n";
	}
	
	 cout << "Apakah simetris? ";
	 if (simetris) {
		cout << "Ya\n";
	}else {
		cout << "Tidak\n";
	 }
	 
}
