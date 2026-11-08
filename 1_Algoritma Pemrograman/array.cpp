#include <iostream>
using namespace std;

int main () {
	int i, nilaiTeori [5] = {50, 55, 40, 50, 60};
	int nilaiPraktek [5] = {42, 45, 20, 49, 33};
	int totalNilai=0;
	for (i=0;i<5;i++){
		totalNilai = totalNilai + nilaiTeori[i] + nilaiPraktek[i];
		cout << "Total Nilai Tugas " << i+1 << ": " << totalNilai << endl;
		totalNilai = totalNilai * 0;
	}
	
}
