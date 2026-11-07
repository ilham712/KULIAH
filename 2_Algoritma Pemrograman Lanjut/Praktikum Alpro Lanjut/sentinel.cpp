#include <iostream>
using namespace std;

int main () {
    int arr[9] = {8, 9, 3, 7, 10, 2, 1, 11}; 
    
    int cariNilai = 3;

    arr[8] = cariNilai; // sentinel

    int i = 0;

    while (arr[i] != cariNilai) {
        i++;
    }

    if (i == 8) {
        cout << "Tidak Ketemu";
    } else {
        cout << "Ketemu di indeks " << i;
    }
}
