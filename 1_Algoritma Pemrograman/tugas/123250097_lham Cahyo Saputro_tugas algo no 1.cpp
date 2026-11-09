#include <iostream>
using namespace std;

int main () {
	int i, n;
	bool prima = true;
	
	cout << "Masukkan bilangan bulat positif: ";
	cin >> n;
	
	if (n == 0 || n == 1){
		prima = false;
	}
	
	for (i=2;i<=n/2;i++){
		if (n % i == 0){
			prima = false;
			break;
		}	
	}
	
	if (prima){
		cout << n << " adalah bilangan prima";
	}else {
		cout << n << " adalah bukan bilangan prima";
	}
	
	return 0;
}
