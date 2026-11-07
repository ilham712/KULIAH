#include <iostream>
using namespace std;

int main () {
	int n = 8;
	int arr[n] = {7, 5, 1, 8, 4, 6, 2, 3};
	
	cout << "Before: " << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	for (int i = 0; i < n-1; i++) {
		for (int j = 1; j < n-i; j++) {
			// kalo semisal bilngan kiri lebih besar dari bilangan kanan, maka posisinya ditukar
			if (arr[j-1] > arr[j]) {
				int temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
				// swap(arr[j-1], arr[j]);
			}
		}
	}
	
	cout << "After: " << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
