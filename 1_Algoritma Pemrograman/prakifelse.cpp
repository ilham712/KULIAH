#include <iostream>
using namespace std;

int main(){
	int nilai;
	int masa_studi;
	cout << "masukkan nilai kamu: ";cin >> nilai;
	cout << "masukkan masa studi kamu: ";cin >> masa_studi;
	
	cout << "nilai kamu adalah: ";
	if(nilai >= 85){
		cout << "A" << endl;
	}if(masa_studi < 4) {
		cout << "predikat cumlaude";
	}
	else if (nilai >=75){
		cout << "B";
	}
	else if (nilai > 60){
		cout << "C";
	}else{
		cout << "Tidak lulus";
	}
	return 0;
}

