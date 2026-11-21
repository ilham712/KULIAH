#include <iostream>
using namespace std;

int main(){
	string nama;
	int nim;
	string kelas;
	
	cout << "Masukkan Nama: " << endl;
	getline(cin, nama);
	cout << "nama: " << nama << endl;
	
	cout << "Masukkan NIM: " << endl;
	cin >> nim;
	cout << "NIM: " << nim << endl;
	
	cout << "Masukkan Kelas: " << endl;
	getline(cin, kelas);
	cout << "kelas: " << kelas;
	
	return 0;
}
