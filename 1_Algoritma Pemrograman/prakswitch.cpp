#include <iostream>
using namespace std;

int main(){
	int menu;
	cout << "Top Up Game" << endl;
	cout << "1. ML" << endl;
	cout << "2. FF" << endl;
	cout << "3. PUBG" << endl;
	cout << "pilih menu: " ;
	cin >> menu;
	switch(menu){
		case 1:
			cout << "Anda memilih ML" << endl;
			break;
		case 2:
			cout << "Anda memilih FF" << endl;
			break;
		case 3:
			cout << "Anda memilih PUBG" << endl;
			break;
		default:
			cout << "EROR";
	}
	return 0;
}


