#include <iostream>
using namespace std;

int main() {
		string kasus;
		string kondisi;
		string odpInput;
		bool ODP;
		
		cout << "Kasus (positif/negatif): ";
		cin >> kasus;
		cout << "Kondisi (hidup/meninggal): ";
		cin >> kondisi;
		cout << "Apakah ODP (ya/tidak): ";
		cin >> odpInput;
		
		if(odpInput == "ya") {
			ODP = true;
		}else{
			ODP = false;
		}
		
		if (kasus == "positif" && kondisi == "meninggal" && ODP == true){
			cout << "ZONA HITAM";
		}else if (kasus == "positif" && kondisi == "hidup" && ODP == true){
			cout << "ZONA MERAH";
		}else if (kasus == "negatif" && kondisi == "hidup" && ODP == true){
			cout << "ZONA ORANGE";
		}else if (kasus == "negatif" && kondisi == "hidup" && ODP == false){
			cout << "ZONA HIJAU";
		}else{
				cout << "ZONA TIDAK TERDETEKSI";
		}
		
}
