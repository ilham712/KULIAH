#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

struct AtributSihir {
  // TODO: Isi dengan variabel Teori, Praktek, Level_Fokus (tipe integer)
  int teori;
  int praktek;
  int level_fokus;
};

struct Siswa {
  // TODO: Isi dengan variabel ID (int), Nama (string), Asrama (string)
  // Jangan lupa panggil struct AtributSihir di sini dengan nama variabel: Statistik
  int id;
  string nama;
  string asrama;
  AtributSihir Statistik;
  
};

// <<===  VARIABEL GLOBAL ===>>
Siswa arraySiswa[100];
int jumlah_siswa = 0;

void initData();          // Dijalankan HANYA DI AWAL saat program pertama kali dibuka
void saveAppendData();    // Digunakan khusus untuk menu Tambah Data (ios::app)
void saveOverwriteData(); // Digunakan khusus untuk menu Hapus Data (overwrite)

int Hitung_Bonus(int fokus);
int binarySearch(Siswa arr[], int kiri, int kanan, int id_cari);

// Fungsi Pointer dan Sorting (Quick Sort)
void swapData(Siswa *a, Siswa *b);
int partition(Siswa arr[], int low, int high);
void quickSort(Siswa arr[], int low, int high);

// Fungsi Menu 
void tambahData();
void lihatData();
void hapusData();
void cetakLaporan();

int main() {
  initData(); 
    
  int pilihan;
  do {
    cout << "\n=== SISTEM MANAJEMEN AKADEMI SIHIR ===\n";
    cout << "[1] Tambah Data Siswa\n";
    cout << "[2] Lihat Data Siswa\n";
    cout << "[3] Hapus Data Siswa\n";
    cout << "[4] Cetak Laporan Kelas Remedial\n";
    cout << "[0] Keluar\n";
    cout << "Pilih menu: ";
    cin >> pilihan;
    cin.ignore();
      
    switch (pilihan) {
      case 1: 
		system("cls");
        tambahData(); 
        break;
      case 2: 
		system("cls");
        lihatData(); 
        break;
      case 3: 
		system("cls");
        hapusData(); 
        break;
      case 4: 
		system("cls");
        cetakLaporan(); 
        break;
      case 0: 
        cout << "Keluar dari program...\n"; 
        break;
      default:
		system("cls");
        cout << "Pilihan tidak valid! Silakan coba lagi.\n";
    }
  } while (pilihan != 0);
    
  return 0;
}

// <<===  FUNGSI FILE ===>>
void initData() {
  // TODO: Baca data dari file data_siswa.txt dan masukkan ke dalam arraySiswa.
  ifstream file("data_siswa.txt");
  if (!file.is_open()) {
    jumlah_siswa = 0;
    return;
  }
  string line;
  while (getline(file, line) && jumlah_siswa < 100) {
    if (line.empty()) {
      continue;
    }
    stringstream ss(line);
    string token;
    getline(ss, token, '|'); arraySiswa[jumlah_siswa].id = stoi(token);
    getline(ss, token, '|'); arraySiswa[jumlah_siswa].nama = token;
    getline(ss, token, '|'); arraySiswa[jumlah_siswa].asrama = token;
    getline(ss, token, '|'); arraySiswa[jumlah_siswa].Statistik.teori = stoi(token);
    getline(ss, token, '|'); arraySiswa[jumlah_siswa].Statistik.praktek = stoi(token);
    getline(ss, token, '|'); arraySiswa[jumlah_siswa].Statistik.level_fokus = stoi(token);
    jumlah_siswa++;
  }
  file.close();
}

void saveAppendData() {
  // KETERANGAN: Dipanggil khusus setelah berhasil menambahkan data baru
  // TODO: Tambahkan 1 data siswa terbaru dari array ke bagian bawah file data_siswa.txt (mode append).
  ofstream file("data_siswa.txt", ios::app);
  if (file.is_open()) {
    Siswa &s = arraySiswa[jumlah_siswa - 1];
    file << s.id << "|" << s.nama << "|" << s.asrama << "|"
         << s.Statistik.teori << "|" << s.Statistik.praktek << "|"
         << s.Statistik.level_fokus << "\n";
    file.close();
  }
  
}

void saveOverwriteData() {
  // KETERANGAN: Dipanggil khusus setelah berhasil menghapus data (shift-left)
  // TODO: Tulis ulang (overwrite) seluruh isi arraySiswa ke dalam file data_siswa.txt.
  ofstream file("data_siswa.txt", ios::out | ios::trunc);
    if (file.is_open()) {
      for (int i = 0; i < jumlah_siswa; i++) {
      Siswa &s = arraySiswa[i];
      file << s.id << "|" << s.nama << "|" << s.asrama << "|"
           << s.Statistik.teori << "|" << s.Statistik.praktek << "|"
           << s.Statistik.level_fokus << "\n";
      }
      file.close();
    }
}

// <<===  FUNGSI REKURSI & SEARCHING ===>>
int Hitung_Bonus(int fokus) {
  // TODO: Hitung bonus resonansi mana menggunakan fungsi rekursif.
  if (fokus == 0) {
    return 0;
  }
  int bonus = (fokus * 10) + Hitung_Bonus(fokus - 1);
  return bonus; 
}

int binarySearch(Siswa arr[], int kiri, int kanan, int id_cari) {
  // TODO: Lakukan pencarian indeks array berdasarkan ID menggunakan algoritma Binary Search.
  while (kiri <= kanan) {
    int mid = kiri + (kanan - kiri) / 2;
    if (arr[mid].id == id_cari) {
      return mid;
    } 
    else if (arr[mid].id < id_cari) {
      kiri = mid + 1;
    } 
    else {
      kanan = mid - 1;
    }
  }
  return -1;
}


// <<===  FUNGSI SORTING ===>>
void swapData(Siswa *a, Siswa *b) {
  // TODO: Tukar nilai data struct menggunakan parameter Pointer
  Siswa temp = *a;
  *a = *b;
  *b = temp;
}

int partition(Siswa arr[], int low, int high) {
  // TODO: Tulis algoritma Quick Sort
  int pivot = arr[high].id;
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j].id <= pivot) {
      i++;
      swapData(&arr[i], &arr[j]);
    }
  }
   swapData(&arr[i + 1], &arr[high]);
   return i + 1;
}

void quickSort(Siswa arr[], int low, int high) {
  // TODO: Tulis algoritma Quick Sort
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

// <<===  FITUR MENU ===>>
void tambahData() {
  // TODO: Minta input data siswa baru, masukkan ke dalam array, lalu simpan ke file secara real-time.
  if (jumlah_siswa >= 100) {
    cout << "Array penuhh!! Tidak bisa menambah data.\n";
    system("pause");
    system("cls");
    return;
  }

  cout << "\n<--- Tambah Data Siswa --->\n";
  int id_input;
  cout << "ID: ";
  cin >> id_input;

  //Validasi ketika ada ID duplikat atau id yang udah ada datanya
  for (int i = 0; i < jumlah_siswa; i++) {
    if (arraySiswa[i].id == id_input) {
      cout << "ID sudah terdaftar!!\n";
      system("pause");
      system("cls");
      return;
    }
  }

  arraySiswa[jumlah_siswa].id = id_input;
  cout << "Nama: "; cin.ignore(); getline(cin, arraySiswa[jumlah_siswa].nama);
  cout << "Asrama: "; getline(cin, arraySiswa[jumlah_siswa].asrama);
  cout << "Teori (0-100): "; cin >> arraySiswa[jumlah_siswa].Statistik.teori;
  cout << "Praktek (0-100): "; cin >> arraySiswa[jumlah_siswa].Statistik.praktek;
  cout << "Level Fokus (1-5): "; cin >> arraySiswa[jumlah_siswa].Statistik.level_fokus;
  cin.ignore();
  
  if (arraySiswa[jumlah_siswa].Statistik.teori < 0 || arraySiswa[jumlah_siswa].Statistik.teori > 100 ||
    arraySiswa[jumlah_siswa].Statistik.praktek < 0 || arraySiswa[jumlah_siswa].Statistik.praktek > 100 ||
    arraySiswa[jumlah_siswa].Statistik.level_fokus < 1 || arraySiswa[jumlah_siswa].Statistik.level_fokus > 5) {
    cout << "Input nilai di luar rentang valid. Data tidak disimpan.\n";
    system("pause");
    system("cls");
    return;
  }

  jumlah_siswa++;
  saveAppendData();
  cout << "Data berhasil ditambahkan!!\n";
  system("pause");
  system("cls");
}

void lihatData() {
  // TODO: Urutkan data menggunakan Quick Sort, lalu tampilkan semua data beserta perhitungan Total Mana-nya.
  if (jumlah_siswa == 0) {
    cout << "Data masih kosong.\n";
    system("pause");
    system("cls");
    return;
  }
  quickSort(arraySiswa, 0, jumlah_siswa - 1);

  cout << "\n<--- DATA SISWA (TERURUT BERDASARKAN ID) --->\n";
  cout << left << setw(5) << "ID" << setw(18) << "Nama" << setw(15) << "Asrama"
       << setw(8) << "Teori" << setw(10) << "Praktek" << setw(8) << "Fokus"
       << setw(8) << "Bonus" << setw(10) << "Total Mana" << endl;
  cout << string(90, '-') << endl;

  for (int i = 0; i < jumlah_siswa; i++) {
    int bonus = Hitung_Bonus(arraySiswa[i].Statistik.level_fokus);
    int total = arraySiswa[i].Statistik.teori + arraySiswa[i].Statistik.praktek + bonus;
    cout << left << setw(5) << arraySiswa[i].id
         << setw(18) << arraySiswa[i].nama
         << setw(15) << arraySiswa[i].asrama
         << setw(8) << arraySiswa[i].Statistik.teori
         << setw(10) << arraySiswa[i].Statistik.praktek
         << setw(8) << arraySiswa[i].Statistik.level_fokus
         << setw(8) << bonus
         << setw(10) << total << endl;
  }
  system("pause");
  system("cls");
  
}

void hapusData() {
  // TODO: Cari ID siswa, hapus datanya dari array (Shift Left), lalu perbarui file secara real-time.
  if (jumlah_siswa == 0) {
    cout << "Data masih kosong.\n";
    system("pause");
    system("cls");
    return;
  }
  int id_cari;
  cout << "\nMasukkan ID siswa yang ingin dihapus: ";
  cin >> id_cari; cin.ignore();
  
  quickSort(arraySiswa, 0, jumlah_siswa - 1);
  int idx = binarySearch(arraySiswa, 0, jumlah_siswa - 1, id_cari);

  if (idx == -1) {
    cout << "ID Siswa tidak ditemukan!\n";
    system("pause");
    system("cls");
    return;
  }

  // Shift Left
  for (int i = idx; i < jumlah_siswa - 1; i++) {
    arraySiswa[i] = arraySiswa[i + 1];
  }
  jumlah_siswa--;
  saveOverwriteData();
  cout << "Data berhasil dihapus!!\n";
  
  system("pause");
  system("cls");
}

void cetakLaporan() {
  // TODO: Cetak data siswa yang memiliki Total Mana < 150 ke dalam file kelas_remedial.txt.
    ofstream report("kelas_remedial.txt", ios::out | ios::trunc);
    if (!report.is_open()) {
        cout << "Gagal membuka file laporan.\n";
        system("pause");
		system("cls");
        return;
    }

    report << "<--- LAPORAN KELAS REMEDIAL (Total Mana < 150) --->\n";
    report << left << setw(5) << "ID" << setw(18) << "Nama" << setw(15) << "Asrama" << setw(15) << "Total Mana" << endl;
    report << string(55, '-') << endl;

    int count = 0;
    for (int i = 0; i < jumlah_siswa; i++) {
        int bonus = Hitung_Bonus(arraySiswa[i].Statistik.level_fokus);
        int total = arraySiswa[i].Statistik.teori + arraySiswa[i].Statistik.praktek + bonus;
        if (total < 150) {
            report << left << setw(5) << arraySiswa[i].id
                   << setw(18) << arraySiswa[i].nama
                   << setw(15) << arraySiswa[i].asrama
                   << setw(15) << total << endl;
            count++;
        }
    }
    report.close();
    cout << "Laporan berhasil dicetak ke file kelas_remedial.txt! (" << count << " siswa)\n";
    
    system("pause");
    system("cls");
}
