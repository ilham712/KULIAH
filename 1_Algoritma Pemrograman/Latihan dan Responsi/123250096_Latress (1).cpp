#include <iostream>
using namespace std;
float hitungkembalian(long total, long bayar);

int main () {
	string useralgo = "algo";
	string passasik = "asyik";
	string username;
	string password;
	string ulang;
	int pilih;
	bool exit=false;
	string kembalimenu;
	long nik=0;
	string nama;
	int pilihkategori;
	long kategori[2]={100000,50000};
	int tiket =0;
	string voucher = "MUYPJ";
	string inputvoucher;
	long bayar =0;
	long total=0;
	long kembalian=0;
	
	//Perulangan masukan nama dan password
	do {
		cout<<"=====SELAMAT DATANG SILAHKAN INPUT USERNAME DAN PASSWORD=====\n";
		cout<<"Masukkan username : ";
		cin>>username;
		cout<<"Masukkan password : ";
		cin>>password;
		
		if(username==useralgo && password==passasik){
			cout<<"Login Berhasil\n";
			system("pause");
		}
		else {
			cout<<"Maaf Salah \nCoba lagi?? (y/t) = ";
			cin>>ulang;
			if(ulang=="T"||ulang=="t"){
				goto selesai;
			}
		}
		system("cls");
	}while (ulang=="Y" || ulang=="y");
	
	//Perulangan menu utama, loop ketika user input tidak mengulang atau input 4.exit
do{
	//Tampilan menu utama dan user memilih
	cout<<"===Menu Utama===";
	cout<<"\n1. Tampilkan Tiket \n2. Pembelian Tiket \n3. Lihat Pesanan \n4. Exit\n";
	cout<<"Pilih Menu : ";
	cin>>pilih;
	system("cls");
	
	if (pilih==1){//sub menu ke 1
		cout<<"===CERMATI LIST HARGA TIKET===\n";
		cout<<"==Kategori Tiket [1]==\n";
		cout<<"Jenis Tiket  :  VIP\n";
		cout<<"Harga Tiket  :  100.000\n\n";
		cout<<"==Kategori Tiket [2]==\n";
		cout<<"Jenis Tiket  :  Festival\n";
		cout<<"Harga Tiket  :  50.000\n";
		cout<<"Kembali ke Menu dan lakukan pembelian ? (y/t)";
		cin>>kembalimenu;
		system("cls");
		if(kembalimenu=="Y"||kembalimenu=="y"){
			exit = false;
		}
		else return 0;
	}
	else if(pilih==2){//sub menu ke 2
		cout<<"===SILAHKAN INPUT NIK DAN NAMA===\n";
		cout<<"NIK Buyer : ";
		cin>>nik;
		cout<<"Nama Buyer : ";
		cin>>nama;
		do {//loop ketika user input pilihkategory diluar (1-2)
			cout<<"Nomor Kategori Tiket : ";
			cin>>pilihkategori;
			//menghitung total harga
			if(pilihkategori==1){
				cout<<"Harga : 100.000\n";
				cout<<"Jumlah Tiket : ";
				cin>>tiket;
				total=tiket*kategori[0];
				cout<<"Total : "<<total<<endl;
			}
			else if(pilihkategori==2){
				cout<<"Harga : 50.000\n";
				cout<<"Jumlah Tiket : ";
				cin>>tiket;
				total=tiket*kategori[1];
				cout<<"Total : "<<total<<endl;
			}else {
			cout<<"Pilihan tidak tersedia, Kategori hanya tersedia 1-2\n";
			}
		}while(pilihkategori<1 || pilihkategori>2);
		
		do{	//loop input voucher
			cout<<"Input Voucher (Jika tidak ada isi [T]) : ";
			cin>>inputvoucher;
			if(inputvoucher==voucher){
				total=total*0.9;
				cout<<"Selamat Anda mendapatkan diskon 10%\n";
				break;
			}
			else if(inputvoucher=="T" ||inputvoucher=="t" ){
				cout<<"Anda tanpa Voucher\n";
				break;
			}
			else {
			cout<<"Voucher tidak valid, Cobalagi?? (y/t) : ";
			cin>>ulang;	
				if(ulang=="T" || ulang=="t"){
				cout<<"Anda tanpa Voucher\n";
				}
			}
		}while (ulang=="y"||ulang=="Y");
		
			do{//loop pmebayaran ketika kurang
				cout<<"Total Pembayaran sekarang : "<<total<<endl;
				cout<<"Nominal Pembayaran : ";
				cin>>bayar;
				if(bayar>=total){
					kembalian=hitungkembalian(total,bayar);
					cout<<"Kembalian : "<<kembalian<<endl;
				}
				else {
					cout<<"Maaf uang Anda kurang\n";
				}
			}while(bayar<total);		
		cout<<"Kembali ke Menu dan pilih sub menu ke 3 untuk melihat detail pesanan ? (y/t)";
		cin>>kembalimenu;
		if(kembalimenu=="Y"||kembalimenu=="y"){
			exit = false;
		}
		else goto selesai;
		system("cls");
	}
	else if (pilih==3){//sub menu riwayat pesanan
		cout<<"=====PESANAN ANDA=====\n";
		cout<<"NIK Buyer : "<<nik<<endl;
		cout<<"Nama Buyer : "<<nama<<endl;
		cout<<"Nomor Kategori Tiket : "<<pilihkategori<<endl;
		cout<<"Harga : "<<total/tiket<<endl;
		cout<<"Jumlah Tiket : "<<tiket<<endl;
		cout<<"Total : "<<total<<endl;
		cout<<"Nominal Pembayaran : "<<bayar<<endl;
		cout<<"Kembalian : "<<kembalian<<endl;
		cout<<"\n===Terima kasih===\n\n";
	
		cout<<"Kembali ke Menu ? (y/t) : ";
		cin>>kembalimenu;
			if(kembalimenu=="Y"||kembalimenu=="y"){
				exit = false;
			}
			else exit = true;
			system("cls");
	}
	else {
		exit=true;
	}
}while(exit==false);
selesai:;
}

//Fuction hitung kembalian
float hitungkembalian(long total, long bayar){
	float kembalian;
	kembalian=bayar-total;
	return kembalian;
	}
