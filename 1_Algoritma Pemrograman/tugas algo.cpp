#include <iostream>
using namespace std;

int main (){
    string nama; int umur; float tinggi;
    cout << "masukkan nama kamu: "; getline(cin,nama);
    cout << "masukkan umur kamu: "; cin >> umur;
    cout << "masukkan tinggi badan kamu: "; cin >> tinggi;
    
    cout << "Halo " << nama << ", umur Anda " << umur <<
     " tahun, tinggi badan Anda " << tinggi << " cm." << endl;
     
	int tahun_lahir; int tahun_sekarang; int usia;
	cout << "tahun lahir: "; cin >> tahun_lahir;
	cout << "tahun sekarang: "; cin >> tahun_sekarang;
	usia = tahun_sekarang - tahun_lahir;
	cout << "umur kamu adalah " << usia << " tahun" << endl;
	
	float celcius,fahrenheit;
	
	cout << "masukkan suhu (dalam derajat celcius): "; cin >> celcius;
	fahrenheit = (celcius * 9/5) + 32;
	cout <<  "Fahrenheit= " << fahrenheit;
}




 
