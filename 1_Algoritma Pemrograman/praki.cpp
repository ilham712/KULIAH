#include <iostream>
#include <string>
using namespace std;

int main () {
		int a = 10, b = 8;
		int jumlah = a*b;
		cout << a+b << endl;
		cout << a-b << endl;
		cout << jumlah << endl; 
		
		int hargaBuku = 50;
		int hargaPulpen = 5;
		int jumlahBuku = 2;
		int jumlahPulpen = 3;
		
		int totalHargaBuku =  hargaBuku * jumlahBuku;
		int totalHargaPulpen = hargaPulpen * jumlahPulpen;
		
		cout << totalHargaBuku << endl;
		cout << totalHargaPulpen;
		
		return 0;
}
