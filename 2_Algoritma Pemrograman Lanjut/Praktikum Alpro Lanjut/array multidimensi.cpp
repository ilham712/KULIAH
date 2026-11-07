#include <iostream>
using namespace std;

int main() {
   int mat[2][3] = {
	   {1, 2, 3}, {4, 5, 6}
	};
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 3; j++) {
			cout << mat[i][j];
		}
		cout << endl;
	}
	
	cout << endl;
	
	cout << "baris dan kolom dibalik\n";
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 2; j++) {
			cout << mat[j][i];
		}
		cout << endl;
	}
	
	cout << endl;
	cout << endl;
	cout << endl;
	
	
	int tigadimensi[2][3][2] = {
		{
			{1,2}, {3,4}, {5,6}
		},
		{
			{7,8}, {9,10}, {11,12}
		}
	}; 
	for (int i = 0; i < 2; i++){
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 2; k++) {
				cout << tigadimensi[i][j][k];
			}
			cout << endl;
		}
		cout << endl;
	}
}

