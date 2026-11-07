#include <iostream>
using namespace std;

int main () {
	 int n;
	 cout << "Masukkan banyak elemen "; cin >> n;
	 int himp[n];
	 cout << "Masukkan elemen : ";
	 for (int i=1; i<=n; i++) {
		 cin >> himp[i];
	 }
	 int m;
	 cout << "Masukkan bayak elemen himpunan relasi "; cin >> m;
	 int relasi[m][2];
	 cout << "Masukkan elemen himpunan relasi : \n";
	 for (int i=1; i<=m; i++) {
		cin >> relasi[i][1] >> relasi[i][2];
	 }
	 cout << "Himpunan relasi = {";
	 for (int i=1; i<=m; i++) {
		 cout << '(' << relasi[i][1] << ',' << relasi[i][2] << ')' ;
	 }
	 cout << '}' << endl;
	 
	 bool refleksif= false;
	 for (int i=1; i<=m; i++) {
		 if (relasi[i][1]==relasi[i][2]) {
			 refleksif = true;
		 }
	 }
	 cout << "Apakah refleksif? ";
	 if (refleksif) cout << "Ya\n";
	 else cout << "Tidak\n";
	 
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
	 cout << "Apakah simetris? ";
	 if (simetris) cout << "Ya\n";
	 else cout << "Tidak\n";
}
