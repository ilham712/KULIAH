#include <iostream>
using namespace std;

struct Pembuat {
	string nama;
	int umur;
};

struct Buku {
	string judul;
	Pembuat penulis;
};

int main() {
	Buku novel;
	
	novel.judul = "Kisah";
	novel.penulis.nama = "Uknown";
	novel.penulis.umur = 20;
	
	cout << "Judul Buku: " << novel.judul << endl;
	cout << "Nama Penulis: " << novel.penulis.nama << endl;
	cout << "Umur Penulis: " << novel.penulis.umur << endl;
}


