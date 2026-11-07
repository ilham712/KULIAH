#include <iostream>
using namespace std;

int main()
{
    int arr[13] = {1, 2, 3, 4, 5, 5, 5, 5, 6, 7, 8, 9, 10};

    int nilaiCari = 5;
    bool found = false;
    int kiri = 0;
    int kanan = 12;
    int index = -1;

    while (!found && (kiri <= kanan)) {
        int mid = (kiri + kanan) / 2;
        if (arr[mid] == nilaiCari) {
            found = true;
            index = mid;
            break;
        } else{
            if (nilaiCari < arr[mid]) {
                kanan = mid - 1;
            } else {
				kiri = mid + 1;
			}
        }
    }

    if(found) {
        cout << "Nilai " << nilaiCari << " Ditemukan\n";
        
        // 2. Cari batas awal dan akhir dari nilai duplikat
        int idxAwal = index;
        int idxAkhir = index;

        // Geser ke kiri selama nilainya sama
        while (idxAwal > 0 && arr[idxAwal - 1] == nilaiCari) {
            idxAwal--;
        }

        // Geser ke kanan selama nilainya sama
        while (idxAkhir < 11 && arr[idxAkhir + 1] == nilaiCari) {
            idxAkhir++;
        }
        
        int jumlahNilaiCari = idxAkhir - idxAwal + 1;

        // 3. Tampilkan semua index
        cout << "Nilai " << nilaiCari << " Ditemukan di index ke- ";
        for (int i = idxAwal; i <= idxAkhir; i++) {
            cout << i;
            // Tambahkan koma jika bukan elemen terakhir
            if (i < idxAkhir) {
                cout << ", ";
            }
        }
        
        cout << "\nJumlah Nilai yang ditemukan : " << jumlahNilaiCari;
    } else {
        cout << "Nilai Tidak Ditemukan\n";
    }
    
    return 0;
}
