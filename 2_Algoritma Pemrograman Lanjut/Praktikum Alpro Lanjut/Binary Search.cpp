#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int nilaiCari = 1;
    bool found = false;
    int kiri = 0;
    int kanan = 10;

    while (!found && (kiri <= kanan)) {
        int mid = (kiri + kanan) / 2;
        if (arr[mid] == nilaiCari) {
            found = 1;
        } else{
            if (nilaiCari < arr[mid]) {
                kanan = mid - 1;
            } else {
				kiri = mid + 1;
			}
        }
    }

    if(found) {
        cout << "Nilai Ditemukan\n";
    } else {
        cout << "Nilai Tidak Ditemukan\n";
    }
}
