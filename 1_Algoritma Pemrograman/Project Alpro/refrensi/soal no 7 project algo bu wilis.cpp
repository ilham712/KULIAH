#include <iostream>
using namespace std;
void satuan(int angka);

int main(){
	int angka;
	string ulang;
	
	do{
		cout<<"Masukkan angka = ";
		cin>>angka;
		
		satuan(angka);
		
		cout<<"Terbilang : ";
		if(angka<10){
			satuan(angka);
		}
		else if(angka==10){
			cout<<"sepuluh";
		}
		else if(angka==11){
			cout<<"sebelas";
		}
		else if(angka>11 && angka<20){
			satuan(angka%10);
			cout<<" belas";
		}
		else if(angka%10==0){
			satuan(angka/10);
			cout<<" puluh";	
		}
		else if(angka>=21 && angka<=99){
			satuan(angka/10);
			cout<<" puluh ";
			satuan(angka%10);
		}
		
		
		cout<<"\nApakah mau ulangi?? (y/t) = ";
		cin>>ulang;
		
	system("cls");
	}while (ulang=="Y" || ulang=="y");
	
}

void satuan(int angka){
	switch(angka){
		case 1 : cout<<"satu"; break;
		case 2 : cout<<"dua"; break;
		case 3 : cout<<"tiga"; break;
		case 4 : cout<<"empat"; break;
		case 5 : cout<<"lima"; break;
		case 6 : cout<<"enam"; break;
		case 7 : cout<<"tujuh"; break;
		case 8 : cout<<"delapan"; break;
		case 9 : cout<<"sembilan"; break;
		}
	}
