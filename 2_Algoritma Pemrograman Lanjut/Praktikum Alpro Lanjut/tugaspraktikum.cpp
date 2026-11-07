#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Silakan Masukkan Index yang diinginkan: ";
    cin >> n;

    int arr[n];
    int nilaiCari;

    for (int i = 0; i < n; i++){
        cout << "Masukkan Nilai ke- " << i+1 << ": ";
        cin >> arr[i];
    }
    
    cout << endl;
    
    for (int j = 0; j < n; j++){
        cout << "Nilai ke- " << j+1 << ": " << arr[j] << endl;
    }
	
	cout << "Masukkan angka yang dicari: ";
	cin >> nilaiCari;

    sort(arr, arr + n);

    
    bool found = false;
    int kiri = 0;
    int kanan = 10;
    int mid;

    while (found && (kiri <= kanan))
    {
        mid = (kiri + kanan) / 2;
        if (arr[mid] == nilaiCari)
        {
            found = true;
        }
        else
        {
            if (nilaiCari < arr[mid])
            {
                kanan = mid - 1;
            }
            else
            {
                kiri = mid + 1;
            }
        }
    }

    if(found)
    {
        cout << "Nilai Ditemukan\n";
    }
    else
    {
        cout << "Nilai Tidak Ditemukan\n";
    }
}

