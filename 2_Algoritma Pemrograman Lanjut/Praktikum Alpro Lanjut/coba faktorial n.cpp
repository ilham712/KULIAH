#include <iostream>
using namespace std;

int faktorial (int n) {
	int k = n;
	// int n = 1;
	
	if (n == k) {
		return 1;
	} else {
		return n * (faktorial (n+1));
	}
}


int main() {
	int n = 1;
	cout << faktorial(n);

   return 0;
}

