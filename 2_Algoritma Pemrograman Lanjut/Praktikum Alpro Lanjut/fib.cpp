#include <iostream>
using namespace std;

int fib (int n) {
	if (n == 1 || n == 2) {
		return 1;
	} else {
		return fib(n-1) + fib(n-2);
	}
}


int main() {
   int n = 3;
   cout << "Bilangan Fibonaci ke-" << n << ": " << fib(n);
   return 0;
}
