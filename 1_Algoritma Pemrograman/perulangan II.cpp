#include <iostream>
using namespace std;

int main () {
	int energi = 100;
	int tinggiGunung;
	int ketinggianSekarang;
	int naik = 100;
	
	cout << "Selamat datang di pendakian gunung misterius!! \n";
	cout << "Masukkan ketinggian gunung yang anda daki:  ";
	cin >> tinggiGunung;
	cout << "\nGunung yang akan anda daki adalah " << tinggiGunung << " meter \n";
	cout << "Energi kamu adalah " << energi << endl;
	
	for(ketinggianSekarang = 0; ketinggianSekarang  <= tinggiGunung; ketinggianSekarang += naik) {
		if (ketinggianSekarang % 100 == 0 && ketinggianSekarang < 0){
			cout << "Ketinggian saat ini adalah: " << ketinggianSekarang << endl << endl;
			energi = energi - 5;
			cout << "Energi tersisa: " << energi << endl;
		}
		
		}		
	
	
}
