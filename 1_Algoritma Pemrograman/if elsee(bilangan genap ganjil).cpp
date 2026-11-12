#include <iostream>
using namespace std;

int main () {
	int bil;
	 cout << "Input bilangan : "; cin >> bil;
	 
	 cout << bil << " merupakan bilangan kelipatan ";
	 if (bil % 2 == 0 && bil % 3 == 0 && bil % 5 == 0){
		cout << "2,3,5 \n";
	}
	else if (bil % 2 == 0 && bil % 3 == 0){
		cout << "2,3 \n";
	}
	else if (bil % 2 == 0 && bil % 5 == 0){
		cout << "2,5 \n";
	}
	else if (bil % 3 == 0 && bil % 5 == 0){
		cout << "3,5 \n";
	}
	else if (bil % 2 == 0){
		cout << "2 \n";
	}
	else if (bil % 3 == 0){
		cout << "3 \n";
	}
	else if (bil % 5 == 0){
		cout << "5 \n";
	}
	else {
		cout << "bukan ketiganya \n";
	}
	
	cout << bil << " merupakan bilangan ";
	if (bil % 2 == 0) {
		cout << "genap";
	}
	else {
		cout << "ganjil";
	}

	return 0;
}
