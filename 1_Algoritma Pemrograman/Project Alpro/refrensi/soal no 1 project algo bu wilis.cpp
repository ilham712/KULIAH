#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Berapa jumlah mahasiswa yang diinginkan = ";
    cin >> n;
    int nilai[n];

    int i = 0;
    while (i < n) {
        cout << "Nilai mahasiswa ke-" << i + 1 << " = ";
        cin >> nilai[i];
        i++;
    }

    int j = 0;
    int maks = nilai[0];
    while (j < n) {
        if (nilai[j] > maks) {
            maks = nilai[j];
        }
        j++;
    }

    int k = 0;
    int banyakmaks = 0; 
    while (k < n) {
        if (nilai[k] == maks) {
            banyakmaks = banyakmaks + 1;
        }
        k++;
    }

    cout << "Nilai tertinggi adalah " << maks << endl;
    cout << "Banyak mahasiswa yang mempunyai nilai tertinggi adalah " << banyakmaks << endl;
    
    return 0;
}


