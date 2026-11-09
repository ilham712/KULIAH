#include <iostream>
using namespace std;
string pin = "admin123";
string password;
int coba = 0;

int main () {
	cout << "Selamat datang di Bank UPN \n";
	cout << "Silakan masukkan password Anda: ";
	cin >> password;
	
	
	
	
	/*
	do {
		if (password != pin) {
			cout << "Password salah, silakan coba lagi! \n";
			cout << "Password: ";
			cin >> password;
			coba++;
			cout << "sisa percobaan " << 3 - coba << endl;
		} else if (password == pin){
			cout << "Password Anda benar \n";
			cout << "Selamat datang di akun Anda";
			exit(0);
		}
	}while (coba < 3); 
		cout << "Anda terlalu banyak salah, akun Anda diblokir";
	*/
	
	
	
	
	
	/*
	while (coba < 3){
		if (password != pin) {
			cout << "Password salah, silakan coba lagi! \n";
			cout << "Password: ";
			cin >> password;
			coba++;
			cout << "sisa percobaan " << 3 - coba << endl;
		} else if (password == pin){
			cout << "Password Anda benar \n";
			cout << "Selamat datang di akun Anda";
			exit(0);
		}
	}
	*/
	return 0;
}
