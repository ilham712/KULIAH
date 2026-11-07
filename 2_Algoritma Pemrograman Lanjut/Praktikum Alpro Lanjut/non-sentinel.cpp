#include <iostream>
using namespace std;

int main () {
    int arr [8] = {8, 9, 3, 7, 10, 2, 1, 11};
    
    bool found = false;
    int cariNilai = 1;

    for(int i = 0; i < 8; i++) {
        if (arr[i] == cariNilai) {
            found = true;
        }
    }

    if(found) {
        cout << "Nilai Ketemuu\n";
    } else {
        cout  << "Nilai tidak ketemu\n";
    }
}
