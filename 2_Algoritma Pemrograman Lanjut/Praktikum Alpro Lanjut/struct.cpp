#include <iostream>
using namespace std;

struct Mahasiswa {
	string nama;
	int umur;
	float ipk;
	int nilai[10];
};

int main() {
	Mahasiswa m[10];
	
	m[0].nama = "Ilham";
	m[0].umur = 20;
	m[0].ipk = 3.81;
	m[0].nilai[0] = 100;
	m[0].nilai[1] = 90;
	
	m[1].nama = "Cahyo";
	m[1].umur = 20;
	m[1].ipk = 3.81;
	m[0].nilai[0] = 90;
	m[0].nilai[1] = 80;
	
	for (int i = 0; i < 2; i++){
		cout << "Nama: " << m[i].nama << endl;
		cout << "Umur: " << m[i].umur << endl;
		cout << "IPK: " << m[i].ipk << endl;
		cout << "Nilai: " << m[i].nilai[i] << endl;
		cout << "Nilai: " << m[i].nilai[i] << endl;
		cout << endl;
	}
	
}

